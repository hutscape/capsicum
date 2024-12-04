---
layout: code
title: Measure raw ADC value
description: Measure raw ADC value using the ESP32-C3 ADC CH0
references:
  - name: Schematic of ESP32-C3-DevKitM-1
    url: https://dl.espressif.com/dl/schematics/SCH_ESP32-C3-DEVKITM-1_V1_20200915A.pdf
  - name: Pinouts
    url: https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/hw-reference/esp32c3/user-guide-devkitm-1.html#pin-layout
  - name: Arduino Pins
    url: https://github.com/espressif/arduino-esp32/blob/master/variants/esp32c3/pins_arduino.h
  - name: How to check the battery voltage
    url: https://wiki.seeedstudio.com/check_battery_voltage/
  - name: Power Management
    url: https://learn.adafruit.com/adafruit-feather-m4-express-atsamd51/power-management#measuring-battery-3010518
  - name: ESP32-C3 ADC issue - reading 4095 at 2.8V
    url: https://forum.arduino.cc/t/esp32-c3-adc-issue-reading-4095-at-2-8v/1127687
  - name: Analog to Digital Converter (ADC)
    url: https://docs.espressif.com/projects/esp-idf/zh_CN/v4.4.2/esp32c3/api-reference/peripherals/adc.html
  - name: Voltage Divider Calculator
    url: https://ohmslawcalculator.com/voltage-divider-calculator
  - name: ESP32 ADC – Read Analog Input in Arduino IDE
    url: https://deepbluembedded.com/esp32-adc-tutorial-read-analog-voltage-arduino/
difficulty: medium
features:
  - esp32c3
  - adc
  - measure
images:
  prototype: analog-battery-adc-prototype.jpeg
  console: analog-battery-adc-console.png
---

This code outputs the reading of the raw ADC value using the ESP32-C3 ADC CH0 of GPIO0 pin.
