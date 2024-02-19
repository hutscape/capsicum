#define DEBUG DBG_VERBOSE
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
#include "Secret.h"

// Timeout for the bell to ring
const int bellTimeout = 30000;  // 30 seconds

// GMT+8 (8 hours * 60 minutes * 60 seconds)
const long timeZoneOffset = 28800;
const int startTime = 9;  // 9am or 0900h
const int endTime = 21;  // 9pm or 2100h

#define BELL_PIN 7
#define LED 3
#define WAKEUP_INTERRUPT_PIN 4

// Connect this pin to HIGH if you want to stay awake
// E.g. for uploading firmware
#define SLEEP_CHECK_PIN 2

Bell bell;
LEDController ledController(LED);
SleepManager sleepManager(WAKEUP_INTERRUPT_PIN, SLEEP_CHECK_PIN);
WiFiConnector wifiConnector(ssid, pass);
TimeManager timeManager(timeZoneOffset, startTime, endTime);
WebhookClient webhookClient;

void setup() {
  Serial.begin(115200);
  while (!Serial) { }

  Debug.setDebugLevel(DEBUG);
  Debug.timestampOn();

  wifiConnector.connect();
  if (wifiConnector.isConnected()) {
    handleConnectedWiFi();
  } else {
    initializeAndRingBell();
  }

  ledController.init();
}

void loop() {
  ledController.blink(1);

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

  // Uncomment below to use for production
  // or to use below the 100/month Zapier limit
  // sendWebhookToZapier();
}

void ringBellIfNeeded() {
  DEBUG_DEBUG("Initializing time manager...");
  timeManager.init();
  DEBUG_DEBUG("Time manager initialized.");

  if (timeManager.isCurrentTimeInRange()) {
    initializeAndRingBell();
  } else {
  DEBUG_DEBUG("Not ringing the bell! The time is not right.");
  }
}

void sendWebhookToZapier() {
  DEBUG_INFO("Sending webhook to Zapier");
  if (!webhookClient.sendWebhook(
      certificateAuthority, server, host, endpoint, 67)) {
    DEBUG_ERROR("Unsuccessful sending to Zapier");
  } else {
    DEBUG_INFO("Successful in sending the webhook to Zapier");
  }
}

void initializeAndRingBell() {
  DEBUG_DEBUG("Initializing bell...");
  bell.init(BELL_PIN);
  DEBUG_DEBUG("Bell initialized.");

  DEBUG_DEBUG("Bell should have rung.");
  bell.ring(bellTimeout);
}
