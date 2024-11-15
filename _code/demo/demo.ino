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
const int bellTimeout = 30000;  // 30 seconds

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

Bell bell;
LEDController ledController(led);
SleepManager sleepManager(wakeupInterruptPin, sleepCheckPin);
WiFiConnector wifiConnector(ssid, pass);
TimeManager timeManager(timeZoneOffset, startTime, endTime);
BatteryLevel batteryLevel(batteryMeasurePin, batteryEnablePin);
WebhookClient webhookClient;
int batt = 0;

void setup() {
  if (DEBUG != DBG_NONE) {
    Serial.begin(115200);
    while (!Serial) { }
  }

  Debug.setDebugLevel(DEBUG);
  Debug.timestampOn();

  wifiConnector.connect();
  if (wifiConnector.isConnected()) {
    handleConnectedWiFi();
  } else {
    DEBUG_ERROR("Not connected to WiFi. Falling back to ringing the bell.");
    initializeAndRingBell();
  }

  batteryLevel.init();
  batt = static_cast<int>(batteryLevel.calculate());
  String debugMessage = "Battery Level: "
    + String(batt)
    + "%";
  DEBUG_INFO(debugMessage.c_str());

  delay(bellTimeout);  // Timeout for the doorbell
  blinkLEDIfBatteryLow(batt);  // Blink LED 10x if battery is below 20%

  #ifndef PRODUCTION
    ledController.init();
  #endif
}

void loop() {
  #ifndef PRODUCTION
    ledController.blink(1000, 1);
  #endif

  if (sleepManager.shouldGoToSleep()) {
    DEBUG_INFO("Going to sleep");
    sleepManager.sleep();
  }

  DEBUG_INFO("Staying awake");
}

void handleConnectedWiFi() {
  DEBUG_INFO("Connected to WiFi SSID ");
  DEBUG_INFO(wifiConnector.getSSID());

  ringBellIfNeeded();

  // Send to Zapier in production environment
  // 100/month Zapier limit
  #ifdef PRODUCTION
    sendWebhookToZapier();
  #endif

  wifiConnector.disconnect();
}

void ringBellIfNeeded() {
  timeManager.init();
  DEBUG_DEBUG("Time manager initialized.");

  if (timeManager.isCurrentTimeInRange()) {
    initializeAndRingBell();
  } else {
  DEBUG_DEBUG("Not ringing the bell! The time is not right.");
  }
}

void sendWebhookToZapier() {
  WebhookClientConfig config = prepareWebhookConfig();

  DEBUG_INFO("Sending webhook to Zapier");
  if (!webhookClient.sendWebhook(&config)) {
    DEBUG_ERROR("Unsuccessful sending to Zapier");
  } else {
    DEBUG_INFO("Successful in sending the webhook to Zapier");
  }
}

void initializeAndRingBell() {
  bell.init(bellPin);
  DEBUG_DEBUG("Bell initialized.");

  String debugMessage = "The bell will ring after a timeout of "
    + String(bellTimeout / 1000.0)
    + " seconds";
  DEBUG_DEBUG(debugMessage.c_str());
  bell.ring();
}

WebhookClientConfig prepareWebhookConfig() {
  const char* environment = "testing";

  #ifdef PRODUCTION
    const char* environment = "production";
  #endif

  WebhookClientConfig config = {
    certificateAuthority,
    server,
    host,
    endpoint,
    batt,
    environment
  };

  return config;
}

void blinkLEDIfBatteryLow(float batt) {
  if (batt < 20) {
    for (int i = 0; i < 10; i++) {
      ledController.blink(500, 40);  // 500ms * 40 = 20 seconds
    }
  }
}
