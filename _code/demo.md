---
layout: code
title: Capsicum Demo
description: Press the doorbell to sound the bell and send a notification if the current time is appropriate
references:
  - name: Schematic of ESP32-C3-DevKitM-1
    url: https://dl.espressif.com/dl/schematics/SCH_ESP32-C3-DEVKITM-1_V1_20200915A.pdf
  - name: Pinouts
    url: https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/hw-reference/esp32c3/user-guide-devkitm-1.html#pin-layout
  - name: Arduino Pins
    url: https://github.com/espressif/arduino-esp32/blob/master/variants/esp32c3/pins_arduino.h
difficulty: medium
features:
  - esp32c3
  - push
  - button
  - buzzer
  - bell
images:
  prototype: demo-prototype.jpg
  console: demo-console.png
  schematic: demo-schematic.png
---

This example shows how to use the ESP32-C3 dev board to do the following:

1. Press the button to wakeup from deep sleep
1. Then, check the current time check with NTP to see if it is appropriate to sound the bell
1. Then, sound the bell if the time is fine
1. Then, send a HTTPS POST to Zapier
1. Then go back to sleep again until the bell is pressed
