#ifndef BELL_H
#define BELL_H

#include "Arduino.h"
#define BELL_PIN 5

class Bell {
public:
  void init();
  void ring();
};

#endif
