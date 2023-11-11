#include "src/sleepManager/sleepManager.h"
#include "src/bell/bell.h"
#include "src/ledController/ledController.h"

#define LED 3  // or use LED_BUILTIN for on-board LED
#define WAKEUP_INTERRUPT_PIN 4

// if GPIO 2 is HIGH, it will not sleep and stay awake
#define SLEEP_CHECK_PIN 2

Bell bell;
SleepManager sleepManager(WAKEUP_INTERRUPT_PIN, SLEEP_CHECK_PIN);
LEDController ledController(LED);

void setup() {
  sleepManager.setup();
  bell.init();
  Serial.begin(115200);
  ledController.init();

  sleepManager.printWakeupReason();

  // TODO(sayanee): Check with NTP for the time
  // to know whether to sound the bell
  Serial.println("\nSound the bell");
  bell.ring();

  // TODO(sayanee): Send HTTPS POST to Zapier
  Serial.println("Blink the LED 10 times");
  ledController.blink(10);
}

void loop() {
  if (sleepManager.shouldGoToSleep()) {
    Serial.println("Going to sleep now");
    sleepManager.sleep();
    Serial.println("This will never be printed");
  }

  Serial.println("Not going to sleep");
  ledController.blink(1);
}
