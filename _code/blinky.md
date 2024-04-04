---
layout: code
title: Blinky
description: Blink the LED
references:
  - name: Schematic of ESP32-C3-DevKitM-1
    url: https://dl.espressif.com/dl/schematics/SCH_ESP32-C3-DEVKITM-1_V1_20200915A.pdf
  - name: Pinouts
    url: https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/hw-reference/esp32c3/user-guide-devkitm-1.html#pin-layout
  - name: Arduino Pins
    url: https://github.com/espressif/arduino-esp32/blob/master/variants/esp32c3/pins_arduino.h
  - name: ESP32 C3 Development Board wont print to serial monitor
    url: https://www.esp32.com/viewtopic.php?t=32621
  - name: ESP32-C3 Serial.available() doesn't work over native USB - print, printf works fine
    url: https://www.esp32.com/viewtopic.php?t=31910
  - name: Cannot view serial monitor after compiling and uploading to ESP32S3
    url: https://forum.arduino.cc/t/cannot-view-serial-monitor-after-compiling-and-uploading-to-esp32s3/1031307
difficulty: medium
features:
  - esp32c3
  - blink
  - led
  - blinky
  - serial
images:
  prototype: blinky-prototype.jpg
  console: blinky-console.png
  schematic: schematic.png
---

Flash in this simplest blinky code to test the PCB.

### Troubleshooting: Cannot view serial prints

On Arduino IDE, enable the option `Tools > USB CDC on Boot > Enabled`

[![Prototype]({{ site.url }}/images/code/blinky-arduino-settings.jpg)]()

or on `arduino-cli`, add the FQBN option as `--fqbn esp32:esp32:esp32c3:CDCOnBoot=cdc`

### Measure power consumption

Connect the test points `GND` and `VBAT` to nRF Power Profiler kit to measure the power consumption. **DO NOT insert the battery in the PCB** to ensure the power is only supplied from the nRF Power Profiler kit.

The power consumption of the PCB is around `20.9mA` when the LED is on and `20.15mA` when the LED is off.

[![Power consumption graph]({{ site.url }}/images/code/blinky-measure-power-graph.png)]()

[![Measure power consumption with nRF profiler kit]({{ site.url }}/images/code/blinky-measure-power.jpg)]()
