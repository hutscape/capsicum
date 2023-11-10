#include "Arduino.h"
#define BELL_PIN 5

#ifndef BELL_H
#define BELL_H

class Bell {
public:
  void init();
  void ring();
};

#endif
