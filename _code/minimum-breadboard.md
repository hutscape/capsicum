---
layout: code
title: Minimum example with breadboard anddev board
description: Press the push button to wake up the ESP32-C3 from deep sleep, sound the bell, and go back to sleep.
references:
  - name: Schematic of ESP32-C3-DevKitM-1
    url: https://dl.espressif.com/dl/schematics/SCH_ESP32-C3-DEVKITM-1_V1_20200915A.pdf
  - name: Pinouts
    url: https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/hw-reference/esp32c3/user-guide-devkitm-1.html#pin-layout
  - name: Arduino Pins
    url: https://github.com/espressif/arduino-esp32/blob/master/variants/esp32c3/pins_arduino.h
difficulty: easy
features:
  - esp32c3
  - push
  - button
  - bell
  - deep
  - sleep
images:
  prototype: minimum-breadboard-prototype.jpg
  console: minumum-breadboard-console.png
  schematic: minimum-breadboard-schematic.png
---

This example uses minimal code and hardware components to demonstrate the doorbell function.

The ESP32-C3 is in deep sleep mode most of the time, consuming very little power. When the push button is pressed, the ESP32-C3 wakes up, sounds the bell, and goes back to sleep.

### Troubleshooting

Initially, the doorbell was vibrating and not sounding. The 3V3 power supply was used from the output of the deb board, which was not sufficient to drive the bell. The 3V3 and GND was connected to the power supply. Then connected to the doorbell directly, and the bell started to sound.

### Research

If your doorbell speaker is vibrating but not producing sound, here are some potential reasons:

1. **Insufficient Voltage or Current**:
   - The 3.3V power supply might not be sufficient to drive the speaker at an audible level. Check the speaker's specifications (e.g., voltage and current requirements).
2. **Damaged Speaker**:
   - The speaker might be defective or partially damaged, leading to vibration without proper sound.
3. **Connection Issues**:
   - Loose or poor connections to the speaker may result in insufficient power or signal transmission.
