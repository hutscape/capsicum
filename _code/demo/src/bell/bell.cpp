#include "bell.h"

void Bell::init() {
  pinMode(BELL_PIN, OUTPUT);
  digitalWrite(BELL_PIN, LOW);
}

void Bell::ring() {
  digitalWrite(BELL_PIN, HIGH);  // Sound is on
  delay(250);
  digitalWrite(BELL_PIN, LOW);  // Sound is off
  delay(250);
}
