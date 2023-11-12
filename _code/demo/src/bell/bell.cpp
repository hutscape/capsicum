#include "bell.h"

void Bell::init(int bellPin) {
  this->bellPin = bellPin;
  pinMode(this->bellPin, OUTPUT);
  digitalWrite(this->bellPin, LOW);
}

void Bell::ring() {
  digitalWrite(this->bellPin, HIGH);
  delay(250);
  digitalWrite(this->bellPin, LOW);
  delay(250);
}
