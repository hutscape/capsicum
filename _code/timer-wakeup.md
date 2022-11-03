---
layout: code
title: Timer wakeup
description: Wakeup every interval and go back to sleep
references:
  - name: Buy the official Espressif devkit
    url: https://www.espressif.com/en/products/devkits/esp32-devkitc/overview
  - name: Schematic of ESP32-S3-DEVKITC-1 V1
    url: https://dl.espressif.com/dl/SCH_ESP32-S3-DEVKITC-1_V1_20210312C.pdf
  - name: Pinouts
    url: https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/esp32s3/user-guide-devkitc-1.html#pin-layout
  - name: Arduino Pins
    url: https://github.com/espressif/arduino-esp32/blob/master/variants/esp32s3/pins_arduino.h
  - name: Timer wakeup code
    url: https://github.com/espressif/arduino-esp32/blob/master/libraries/ESP32/examples/DeepSleep/TimerWakeUp/TimerWakeUp.ino
difficulty: easy
features:
  - timer
  - sleep
  - wakeup
images:
  prototype: esp32s3-prototype.jpeg
  console: timer-wakeup-console.png
steps:
  - step: Plug in the board to the computer
  - step: (Option A) Compile and upload with Arduino IDE
  - step: (Option B) Run `make` to compile and upload with `arduino-cli`
  - step: Access the serial monitor
---

## Flash another Arduino sketch if port is undetected during sleep

1. Plug in the board on the `UART` port
1. Check the port address with `ls /dev/cu.*`
    ```sh
    $ ls /dev/cu.*
    /dev/cu.Bluetooth-Incoming-Port  /dev/cu.SLAB_USBtoUART  /dev/cu.usbserial-1410
    ```
1. Erase the flash
    ```sh
    $ esptool.py --port /dev/cu.usbserial-1410 erase_flash
    ```
1. Plug into the `USB` port of the board
1. Flash in the [blinky example via ESP-IDF](https://hutscape.com/tutorials/blinky-esp-idf-esp32s3)
1. Flash in the [blinky example for Arduino](https://hutscape.com/tutorials/blinky-arduino-esp32s3)
