#ifndef BELL_H
#define BELL_H

#include "Arduino.h"

class Bell {
public:
  void init(int bellPin);
  void ring(int timeout);

private:
  int bellPin;
};

#endif
