#include "LEDController.h"

LEDController::LEDController(int pin)
  : ledPin(pin) {}

void LEDController::init() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void LEDController::blink(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(1000);

    digitalWrite(ledPin, LOW);
    delay(1000);
    Serial.print("Blink ");
    Serial.println(i + 1);
  }
}
