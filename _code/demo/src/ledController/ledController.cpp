#include "LEDController.h"

LEDController::LEDController(int pin)
  : ledPin(pin) {}

void LEDController::init() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void LEDController::blink(int period, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(period);

    digitalWrite(ledPin, LOW);
    delay(period);
  }
}
