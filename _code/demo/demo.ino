#include "src/sleepManager/sleepManager.h"
#include "src/bell/bell.h"

// TODO: Abstract led and use external led
#define LED LED_BUILTIN  // or use LED_BUILTIN for on-board LED
#define INTERRUPT_PIN 4

Bell bell;
SleepManager sleepManager(INTERRUPT_PIN);

bool buttonState = 0;

void setup() {
  sleepManager.setup();
  bell.init();
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  sleepManager.printWakeupReason();

  // TODO: Check with NTP for the time
  // to know whether to sound the bell
  Serial.println("Sound the bell");
  bell.ring();

  // TODO: Send HTTPS POST to Zapier
  Serial.println("Going to blink the LED 10 times");
  blink(10);

  Serial.println("Going to sleep now");
  sleepManager.sleep();
  Serial.println("This will never be printed");
}

void loop() { }

void blink(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED, HIGH);
    delay(1000);

    digitalWrite(LED, LOW);
    delay(1000);
    Serial.print("Blink ");
    Serial.println(i + 1);
  }
}
