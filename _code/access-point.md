---
layout: code
title: Access point
description: Connect to the access point and view the hello world
references:
  - name: Schematic of ESP32-C3-DevKitM-1
    url: https://dl.espressif.com/dl/schematics/SCH_ESP32-C3-DEVKITM-1_V1_20200915A.pdf
  - name: Pinouts
    url: https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/hw-reference/esp32c3/user-guide-devkitm-1.html#pin-layout
  - name: Arduino Pins
    url: https://github.com/espressif/arduino-esp32/blob/master/variants/esp32c3/pins_arduino.h
  - name: Create an Access Point
    url: https://raw.githubusercontent.com/espressif/arduino-esp32/990e3d5b431b63b4adc364b045a79afdad645a3f/libraries/WiFi/examples/WiFiAccessPoint/WiFiAccessPoint.ino
difficulty: medium
features:
  - esp32c3
  - access
  - point
images:
  # prototype: demo-prototype.jpg
  # console: demo-console.png
  # schematic: schematic.png
---

1. Upload the firmware with `make`
1. Remove the USB-C cable used for firmware upload
1. Turn on the power switch
1. Connect to access point `batt` with password `12345678`
1. Browser to `http://192.168.4.1` on the browser
1. View `hello world`
