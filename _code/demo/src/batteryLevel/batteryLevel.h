#ifndef BatteryLevel_h
#define BatteryLevel_h

#include "Arduino.h"

class BatteryLevel {
  public:
    BatteryLevel(int batteryMeasurePin, int batteryEnablePin);
    void init();

    float calculate();
    float calculateADCValue();
    float calculateBatteryVoltage(float adcValue);
    float calculateBatteryLevel(float batteryVoltage);

  private:
    int _batteryMeasurePin;
    int _batteryEnablePin;
    float _voltageDividerRatio = 2.0; // Voltage divider ratio
    float _minVoltage = 3.0; // Minimum voltage
    float _maxVoltage = 4.2; // Maximum voltage
    const int _adcMax = 4095; // Maximum ADC value
    const float _Vref = 2.86; // Reference voltage for ADC
};

#endif
