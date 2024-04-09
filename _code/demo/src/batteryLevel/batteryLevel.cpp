#include "batteryLevel.h"
#include <Arduino.h>

BatteryLevel::BatteryLevel(int enablePin, int measurementPin)
  : _enablePin(enablePin), _measurementPin(measurementPin) {
  pinMode(_enablePin, OUTPUT);
  pinMode(_measurementPin, INPUT);
  digitalWrite(_enablePin, LOW);  // Assume active high enable
}

int BatteryLevel::readLevel() {
  digitalWrite(_enablePin, HIGH);  // Enable measurement
  delay(1);  // Allow time for measurement to stabilize
  int raw = analogRead(_measurementPin);
  digitalWrite(_enablePin, LOW);  // Disable measurement
  // Convert the raw reading to voltage
  return round(raw / 1023.0 * 100);
}
