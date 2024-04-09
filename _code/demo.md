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

<a href="{{ site.raw_content_url }}/_code/demo/power-profiler/demo-power-consumption-no-optimisation.ppk2" class="button is-info">Download nRF PPK2 file</a>

[![Demo power consumption graph with no optimisation]({{ site.url }}/images/code/demo-power-consumption-no-optimisation.jpg)]({{ site.url }}/images/code/demo-power-consumption-no-optimisation.jpg)

### Power consumption with optimisation

Firmware and hardware optimisation can be done to reduce the power consumption:

- remove the power LEDs, TX and RX LEDs
- optimise the firmware to turn off the WiFi and radio as soon as the function is done: `WiFi.disconnect(true);` and `WiFi.mode(WIFI_OFF);`
- optimise the firmware to not blink the user LED

The average power consumption of the PCB with optimisation:

- `73.04uA` in deep sleep mode
- `17.11mA` for `30s` during the timeout after the bell is pressed and the Ding Dong sound is played
- `24.93mA` for `34s` during the entire cycle of the bell press and going to sleep
- `63.99mA` for `6s` during the Ding Dong sound

<a href="{{ site.raw_content_url }}/_code/demo/power-profiler/demo-power-consumption-no-led.ppk2" class="button is-info">Download nRF PPK2 file with no LED</a>

<a href="{{ site.raw_content_url }}/_code/demo/power-profiler/demo-power-consumption-no-radio.ppk2" class="button is-info">Download nRF PPK2 file with no LED and radio/WiFi</a>
[![Demo power consumption graph with optimisation]({{ site.url }}/images/code/demo-power-consumption-optimised.jpg)]({{ site.url }}/images/code/demo-power-consumption-optimised.jpg)
