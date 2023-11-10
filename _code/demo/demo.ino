#include "src/pushButton/pushButton.h"
#include "src/bell/bell.h"

bool buttonState = 0;

void setup() {
  initPushButton();
  initBell();
  Serial.begin(115200);
}

void loop() {
  buttonState = digitalRead(PUSHBUTTON_PIN);
  if (buttonState == LOW) {
    Serial.println("Button pressed!");
    ringTheBell();
  }
}
