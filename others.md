---
layout: others
title: Others
permalink: /others
sequence: 6

# References
similar:
  - name: DIY Wireless Smart Doorbell by The Hook Up
    url: https://github.com/thehookup/Wireless_MQTT_Doorbell
    type: maker
    year: 2018
    components:
      - type: module
        name: nodeMCU
      - type: software stack
        name: Node-Red, MQTT
  - name: SS4H-SD Smart Doorbell
    url: https://smartsolutions4home.com/ss4h-sd-smart-doorbell/
    type: maker
    year: 2020
    components:
      - type: module
        name: ESP32
      - type: software stack
        name: ESPHome, Home Assistant
  - name: Doorbell WiFi Upgrade
    url: https://www.youtube.com/watch?v=NP7_cPEDocI
    type: maker
    year: 2021
    components:
      - type: module
        name: ESP8266
      - type: software stack
        name: Node-Red, WLED

references:
  - topic: ESP32
    list:
      - name: Espressif product comparison
        url: https://products.espressif.com/#/product-comparison

# Schedule
design_start: '2022-04-01'
progress:
  - month: April 2022
    details: Learn about the current doorbell. Wait for ESP32-S3 and ESP32-C3 dev boards to arrive.
---
