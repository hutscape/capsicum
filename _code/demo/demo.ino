#ifdef PRODUCTION
  #define DEBUG DBG_NONE
#else
  #define DEBUG DBG_VERBOSE
#endif
// Change the debug level accordingly:
// DBG_NONE, DBG_ERROR, DBG_WARNING,
// DBG_INFO (default), DBG_DEBUG, and DBG_VERBOSE

#include "Arduino_DebugUtils.h"
#include "src/bell/bell.h"
#include "src/ledController/ledController.h"
#include "src/sleepManager/sleepManager.h"
#include "src/wifiConnector/wifiConnector.h"
#include "src/timeManager/timeManager.h"
#include "src/webhookClient/webhookClient.h"
#include "src/batteryLevel/batteryLevel.h"
#include "Secret.h"

// Timeout for the bell to ring
#ifdef PRODUCTION
  const int bellTimeout = 30000;  // 30 seconds
#else
  const int bellTimeout = 5000;  // 5 seconds
#endif

// GMT+8 (8 hours * 60 minutes * 60 seconds)
const long timeZoneOffset = 28800;
const int startTime = 9;  // 9am or 0900h
const int endTime = 21;  // 9pm or 2100h

const int bellPin = 7;
const int led = 3;
const int wakeupInterruptPin = 4;

// Connect this pin to HIGH if you want to stay awake
// E.g. for uploading firmware
const int sleepCheckPin = 2;

const int batteryEnablePin = 6;
const int batteryMeasurePin = 0;

const int lowBattPeriod = 500;  // 500ms
const int lowBattTimes = 40;  // 40 times
const int LOW_BATTERY_THRESHOLD = 20;

Bell bell;
LEDController ledController(led);
SleepManager sleepManager(wakeupInterruptPin, sleepCheckPin);
WiFiConnector wifiConnector(ssid, pass);
TimeManager timeManager(timeZoneOffset, startTime, endTime);
BatteryLevel batteryLevel(batteryMeasurePin, batteryEnablePin);
WebhookClient webhookClient;
int batt = 0;

void setup() {
  initializeDebug();

  // Check if the device can be connected to WiFi
  if (isWifiConnected()) {
    // If the current time is within the specified range, ring the bell
    if (isCurrentTimeInRange()) {
      ringBell();
    }

    // Display WiFi information on the debug interface
    displayWiFiInfo();

    // Check the battery level
    batt = checkBatteryLevel();

    // Send a webhook to Zapier
    sendWebhookToZapier();

    // Disconnect from WiFi to save power
    wifiConnector.disconnect();
  } else {
     // If not connected to WiFi, ring the bell as a fallback
    ringBell();
    DEBUG_ERROR("Not connected to WiFi. Falling back to ringing the bell.");

    // Check the battery level
    batt = checkBatteryLevel();
  }

  // If the battery level is below the threshold, blink the LED
  if (batt < LOW_BATTERY_THRESHOLD) {
    blinkBatteryLow(lowBattPeriod, lowBattTimes);  // 500ms * 40 = 20 seconds
    delay(bellTimeout - lowBattPeriod*lowBattTimes);
  } else {
    // Otherwise, delay for the doorbell timeout period
    delay(bellTimeout);
  }
}

void loop() {
  if (sleepManager.shouldGoToSleep()) {
    DEBUG_INFO("Going to sleep");
    sleepManager.sleep();
  }

  DEBUG_INFO("Staying awake");  // For debugging purposes
}

void initializeDebug() {
  #ifndef PRODUCTION
  if (DEBUG != DBG_NONE) {
    Serial.begin(115200);
    while (!Serial) {
      delay(10);
    }

    Debug.setDebugLevel(DEBUG);
    Debug.timestampOn();
  }
  #endif
}

bool isWifiConnected() {
  wifiConnector.connect();
  return wifiConnector.isConnected();
}

void displayWiFiInfo() {
  DEBUG_INFO("Connected to WiFi SSID ");
  DEBUG_VERBOSE(wifiConnector.getSSID());
}

bool isCurrentTimeInRange() {
  timeManager.init();
  DEBUG_VERBOSE("Time manager initialised.");

  if (timeManager.isCurrentTimeInRange()) {
    return true;
  } else {
    DEBUG_DEBUG("Not ringing the bell! The time is not right.");
    return false;
  }
}

void ringBell() {
  bell.init(bellPin);
  DEBUG_VERBOSE("Bell initialized.");
  bell.ring();
}

int checkBatteryLevel() {
  batteryLevel.init();
  float batt = batteryLevel.calculate();
  String debugMessage = "Battery Level: "
    + String(batt)
    + "%";
  DEBUG_INFO(debugMessage.c_str());

  return (int)batt;
}

void sendWebhookToZapier() {
  WebhookClientConfig config = prepareWebhookConfig();

  #ifdef PRODUCTION
  // Send to Zapier in production environment
  // 100/month Zapier limit
  DEBUG_INFO("Sending webhook to Zapier");
  if (!webhookClient.sendWebhook(&config)) {
    DEBUG_ERROR("Unsuccessful sending to Zapier");
  } else {
    DEBUG_INFO("Successful in sending the webhook to Zapier");
  }
  #endif
}

WebhookClientConfig prepareWebhookConfig() {
  DEBUG_INFO("Preparing webhook configuration");
  DEBUG_INFO("Host: ");
  DEBUG_INFO(host);
  DEBUG_INFO("Battery Level: ");
  DEBUG_INFO(String(batt).c_str());

  WebhookClientConfig config = {
    certificateAuthority,
    server,
    host,
    endpoint,
    batt
  };

  return config;
}

void blinkBatteryLow(int period, int times) {
  DEBUG_WARNING("Battery is below 20%!");
  ledController.init();
  ledController.blink(period, times);
}
