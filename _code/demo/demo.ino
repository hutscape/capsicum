#include "src/bell/bell.h"
#include "src/ledController/ledController.h"
#include "src/sleepManager/sleepManager.h"
#include "src/wifiConnector/wifiConnector.h"
#include "src/timeManager/timeManager.h"
#include "src/webhookClient/webhookClient.h"
#include "Secret.h"

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
  // TODO(sayanee): Add a debug print for all print statements
  Serial.begin(115200);
  while (!Serial) { }

  wifiConnector.connect();
  if (wifiConnector.isConnected()) {
    Serial.print("Connected to WiFi SSID ");
    Serial.println(wifiConnector.getSSID());
  }
  // TODO(sayanee): If WiFi is not connected, then just ring the bell
  // Else check NTP, ring bell, send webhook

  Serial.println("Initializing bell...");
  bell.init();
  Serial.println("Bell initialized.");

  Serial.println("Initializing time manager...");
  timeManager.init();
  Serial.println("Time manager initialized.");

  if (timeManager.isCurrentTimeInRange()) {
    Serial.println("Ring the bell as its within the time range!");
    bell.ring();
    Serial.println("Bell should have rung.");
  }

  webhookClient.sendWebhook(
    certificateAuthority,
    server,
    host,
    endpoint,
    67);

  sleepManager.setup();
  ledController.init();
}

void loop() {
  if (sleepManager.shouldGoToSleep()) {
    sleepManager.sleep();
  }

  ledController.blink(1);
}
