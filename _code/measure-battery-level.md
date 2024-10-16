---
layout: code
title: Measure battery voltage
description: Measure battery level using the ESP32-C3 ADC
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
  - battery
  - voltage
images:
  prototype: measure-battery-level-prototype.jpg
  console: measure-battery-level-console.png
  schematic: measure-battery-level-schematic.png
---

This code measures the battery voltage using the ESP32-C3 ADC with a voltage divider circuit. The voltage divider circuit is used to scale down the battery voltage to a level that can be measured by the ESP32-C3 ADC. The ESP32-C3 ADC has a 12-bit resolution.

### With Oscilloscope

Channel 1 is connected to the `BATTERY_ENABLE_PIN` where the MOSFET is connected. Channel 2 is connected to the `BATTERY_MEASURE_PIN` where ADC is connected. Every 2 seconds, the MOSFET is turned on and the battery voltage is measured.

![]({{ site.url }}/images/code/measure-battery-level-oscilloscope-1.png)

![]({{ site.url }}/images/code/measure-battery-level-oscilloscope-2.png)

![]({{ site.url }}/images/code/measure-battery-level-oscilloscope-3.png)

Here the oscilloscope is showing the voltage at pin is `2V` and the same is measured by the microcontroller. With the potential divider circuit, the total battery voltage multiplied by 2 and it is `4V`. In the code, we add a `10us` delay before reading the ADC value.

![]({{ site.url }}/images/code/measure-battery-level-console.png)
