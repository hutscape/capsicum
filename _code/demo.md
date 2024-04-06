---
layout: code
title: Demo
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
  schematic: schematic.png
---

This example shows how to use the ESP32-C3 dev board to do the following:

1. Press the button to wakeup from deep sleep
1. Then, check the current time check with NTP to see if it is appropriate to sound the bell
1. Then, sound the bell if the time is fine
1. Then, send a HTTPS POST to Zapier
1. Then go back to sleep again until the bell is pressed

### Power consumption with no optimisation

The average power consumption of the PCB no optimisation:

- with 2 power LEDs
- no firmware optimisation
- radio is on

The average power consumption is:

- `3.87mA` in deep sleep mode
- `25.69mA` for `30s` during the timeout after the bell is pressed and the Ding Dong sound is played
- `31.94mA` for `34s` during the entire cycle of the bell press and going to sleep
- `70.62mA` for `6s` during the Ding Dong sound

[![Demo power consumption graph with no optimisation]({{ site.url }}/images/code/demo-power-consumption-no-optimisation.jpg)]({{ site.url }}/images/code/demo-power-consumption-no-optimisation.jpg)
