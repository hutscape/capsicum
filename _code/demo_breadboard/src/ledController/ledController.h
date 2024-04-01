#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <Arduino.h>

class LEDController {
public:
  LEDController(int pin);

  void init();
  void blink(int times);

private:
  int ledPin;
};

#endif
