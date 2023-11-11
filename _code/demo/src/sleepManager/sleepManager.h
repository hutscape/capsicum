#ifndef SLEEP_MANAGER_H
#define SLEEP_MANAGER_H

#include <Arduino.h>

class SleepManager {
public:
  SleepManager(int wakeupInterruptPin, int sleepCheckPin);

  void setup();
  void sleep();
  bool shouldGoToSleep();
  void printWakeupReason();

private:
  int bootCount;
  int interruptPin;
  int sleepCheckPin;

  void blink(int times);
};

#endif
