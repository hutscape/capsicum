#include "src/sleepManager/sleepManager.h"
#include "src/bell/bell.h"
#include "src/ledController/ledController.h"

#define LED 3  // or use LED_BUILTIN for on-board LED
#define INTERRUPT_PIN 4

Bell bell;
SleepManager sleepManager(INTERRUPT_PIN);
LEDController ledController(LED);

void setup() {
  sleepManager.setup();
  bell.init();
  Serial.begin(115200);
  ledController.init();

  sleepManager.printWakeupReason();

  // TODO(sayanee): Check with NTP for the time
  // to know whether to sound the bell
  Serial.println("Sound the bell");
  bell.ring();

  // TODO(sayanee): Send HTTPS POST to Zapier
  Serial.println("Blink the LED 10 times");
  ledController.blink(10);

  Serial.println("Going to sleep now");
  sleepManager.sleep();
  Serial.println("This will never be printed");
}

void loop() { }
