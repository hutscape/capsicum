#include "bell.h"

void initBell() {
  pinMode(BELL_PIN, OUTPUT);
  digitalWrite(BELL_PIN, LOW);
}

void ringTheBell() {
  digitalWrite(BELL_PIN, HIGH);  // Sound is on
  delay(250);
  digitalWrite(BELL_PIN, LOW);  // Sound is off
  delay(250);
}
