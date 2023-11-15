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

#define BELL_PIN 7
#define LED 3
#define WAKEUP_INTERRUPT_PIN 4

// Connect this pin to HIGH if you want to stay awake
// E.g. for uploading firmware
#define SLEEP_CHECK_PIN 2

// GMT+8 (8 hours * 60 minutes * 60 seconds)
const long timeZoneOffset = 28800;
const int startTime = 9;  // 9am or 0900h
const int endTime = 21;  // 9pm or 2100h

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
    ringBell();
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

  initializeBell();
  ringBellIfNeeded();
  sendWebhookToZapier();
}

void initializeBell() {
  DEBUG_DEBUG("Initializing bell...");
  bell.init(BELL_PIN);
  DEBUG_DEBUG("Bell initialized.");

  DEBUG_DEBUG("Initializing time manager...");
  timeManager.init();
  DEBUG_DEBUG("Time manager initialized.");
}

void ringBellIfNeeded() {
  if (timeManager.isCurrentTimeInRange()) {
    DEBUG_DEBUG("Ring the bell as it's within the time range!");
    bell.ring();
    DEBUG_DEBUG("Bell should have rung.");
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

void ringBell() {
  DEBUG_DEBUG("Initializing bell...");
  bell.init(BELL_PIN);
  DEBUG_DEBUG("Bell initialized.");

  bell.ring();
  DEBUG_DEBUG("Bell should have rung.");
}
