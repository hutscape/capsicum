#include "src/pushButton/pushButton.h"
#include "src/bell/bell.h"

PushButton pushButton;
Bell bell;

bool buttonState = 0;

void setup() {
  pushButton.init();
  bell.init();
  Serial.begin(115200);
}

void loop() {
  buttonState = digitalRead(PUSHBUTTON_PIN);
  if (buttonState == LOW) {
    Serial.println("Bell pressed!");
    bell.ring();
  }
}
