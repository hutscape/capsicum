#ifndef BATTERYLEVEL_H
#define BATTERYLEVEL_H

class BatteryLevel {
public:
  BatteryLevel(int enablePin, int measurementPin);
  int readLevel();

private:
  int _enablePin;
  int _measurementPin;
};

#endif // BATTERYLEVEL_H
