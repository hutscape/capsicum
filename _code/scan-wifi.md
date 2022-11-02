---
layout: code
title: WiFi Scan
description: Hello world with Blinky LED
references:
  - name: Buy the official Espressif devkit
    url: https://www.espressif.com/en/products/devkits/esp32-devkitc/overview
  - name: Schematic of ESP32-S3-DEVKITC-1 V1
    url: https://dl.espressif.com/dl/SCH_ESP32-S3-DEVKITC-1_V1_20210312C.pdf
  - name: Pinouts
    url: https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/esp32s3/user-guide-devkitc-1.html#pin-layout
  - name: KiCad symbol for ESP32-S3-devkitC
    url: https://github.com/espressif/kicad-libraries
  - name: Arduino Pins
    url: https://github.com/espressif/arduino-esp32/blob/master/variants/esp32s3/pins_arduino.h
  - name: WiFi Scan code
    url: https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/examples/WiFiScan/WiFiScan.ino
difficulty: easy
features:
  - wifi
steps:
  - step: Plug in the board to the computer
  - step: (Option A) Compile and upload with Arduino IDE
  - step: (Option B) Run `make` to compile and upload with `arduino-cli`
  - step: Access the serial monitor
---
