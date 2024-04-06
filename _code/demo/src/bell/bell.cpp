#include "bell.h"

void Bell::init(int bellPin) {
  this->bellPin = bellPin;
  pinMode(this->bellPin, OUTPUT);
  digitalWrite(this->bellPin, LOW);
}

// Ring the bell
void Bell::ring() {
  digitalWrite(this->bellPin, HIGH);
  delay(3000);  // 3000ms or 3 seconds is the default duration of the bell
  digitalWrite(this->bellPin, LOW);
  delay(250);  // 250ms or 0.25 seconds
}
