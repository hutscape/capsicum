#ifndef SLEEP_MANAGER_H
#define SLEEP_MANAGER_H

#include <Arduino.h>

class SleepManager {
public:
  SleepManager(int interruptPin);

  void setup();
  void sleep();
  void printWakeupReason();

private:
  int bootCount;
  int interruptPin;

  void blink(int times);
};

#endif
