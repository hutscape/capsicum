#include "bell.h"

void Bell::init(int bellPin) {
  this->bellPin = bellPin;
  pinMode(this->bellPin, OUTPUT);
  digitalWrite(this->bellPin, LOW);
}

// Ring the bell with a parameter for the duration and timeout of the bell
void Bell::ring(int timeout) {
  digitalWrite(this->bellPin, HIGH);
  delay(timeout);
  digitalWrite(this->bellPin, LOW);
  delay(250);
}
