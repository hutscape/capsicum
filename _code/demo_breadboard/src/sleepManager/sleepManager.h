#ifndef SLEEP_MANAGER_H
#define SLEEP_MANAGER_H

#include <Arduino.h>

// Uncomment the line below to enable debug prints
#define DEBUG_SLEEP_MANAGER

class SleepManager {
public:
  SleepManager(int wakeupInterruptPin, int sleepCheckPin);

  void increaseBootNumber();
  int getCurrentBootNumber();
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
