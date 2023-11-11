#include "sleepManager.h"

SleepManager::SleepManager(int wakeupInterruptPin, int sleepCheckPin)
  : bootCount(0), interruptPin(wakeupInterruptPin), sleepCheckPin(sleepCheckPin)  {}

void SleepManager::setup() {
  Serial.begin(115200);
  delay(1000);

  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));
}

void SleepManager::sleep() {
  esp_deep_sleep_enable_gpio_wakeup(1 << interruptPin,
    ESP_GPIO_WAKEUP_GPIO_HIGH);
  esp_deep_sleep_start();
}

bool SleepManager::shouldGoToSleep() {
  return digitalRead(sleepCheckPin) == LOW;
}

void SleepManager::printWakeupReason() {
  esp_sleep_wakeup_cause_t wakeupReason;

  wakeupReason = esp_sleep_get_wakeup_cause();

  switch (wakeupReason) {
    case ESP_SLEEP_WAKEUP_EXT0:
      Serial.println("Wakeup caused by an external signal using RTC_IO");
      break;
    case ESP_SLEEP_WAKEUP_EXT1:
      Serial.println("Wakeup caused by an external signal using RTC_CNTL");
      break;
    case ESP_SLEEP_WAKEUP_TIMER:
      Serial.println("Wakeup caused by a timer");
      break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD:
      Serial.println("Wakeup caused by a touchpad");
      break;
    case ESP_SLEEP_WAKEUP_ULP:
      Serial.println("Wakeup caused by ULP program");
      break;
    default:
      Serial.printf("Wakeup was not caused by deep sleep: %d\n", wakeupReason);
      break;
  }
}
