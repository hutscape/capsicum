#include "Arduino.h"
#include "batteryLevel.h"

BatteryLevel::BatteryLevel(int batteryMeasurePin, int batteryEnablePin)
  : _batteryMeasurePin(batteryMeasurePin), _batteryEnablePin(batteryEnablePin) {}

void BatteryLevel::init() {
  pinMode(_batteryEnablePin, OUTPUT);
  digitalWrite(_batteryEnablePin, HIGH);
}

float BatteryLevel::calculate() {
  float adcValue = calculateADCValue();
  float batteryVoltage = calculateBatteryVoltage(adcValue);
  float batteryLevel = calculateBatteryLevel(batteryVoltage);
  return batteryLevel;
}

float BatteryLevel::calculateADCValue() {
  digitalWrite(_batteryEnablePin, LOW);
  delayMicroseconds(10);

  int sum = 0;
  for (int i = 0; i < 100; i++) {
    sum += analogRead(_batteryMeasurePin);
  }
  float adcValue = sum / 100.0;

  digitalWrite(_batteryEnablePin, HIGH);

  return adcValue;
}

float BatteryLevel::calculateBatteryVoltage(float adcValue) {
  float voltageAtPin = (adcValue / _adcMax) * _Vref;
  float batteryVoltage = voltageAtPin * _voltageDividerRatio;
  return batteryVoltage;
}

float BatteryLevel::calculateBatteryLevel(float batteryVoltage) {
  float batteryLevel = (batteryVoltage - _minVoltage) / (_maxVoltage - _minVoltage) * 100.0;
  return batteryLevel;
}
