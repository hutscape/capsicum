---
layout: others
title: Others
permalink: /others
sequence: 6

# References
similar:
  - name: Adafruit QT Py ESP32-C3 WiFi Dev Board
    url: https://www.adafruit.com/product/5405
    type: maker
    year: 2022
    components:
      - type: module
        name: ESP32-C3H4 (no antenna)
      - type: LDO
        name: AP2112K-3.3
      - type: connector
        name: USB-C
  - name: Olimex ESP32-C3-DevKit-Lipo
    url: https://www.olimex.com/Products/IoT/ESP32-C3/ESP32-C3-DevKit-Lipo/open-source-hardware
    type: maker
    year: 2022
    components:
      - type: module
        name: ESP32-C3-MINI-1-N4 (with PCB antenna and 4MB flash)
      - type: DC-DC regulator
        name: SY8089AAAC
      - type: linear charger for lithium-ion batteries
        name: BL4054B
      - type: connector
        name: USB-C
      - type: battery
        name: LiPo
  - name: LilyGO T-OI Plus
    url: https://www.lilygo.cc/products/t-oi-plus
    type: maker
    year: 2021
    components:
      - type: module
        name: ESP32-C3
      - type: flash
        name: W25Q32FVSS (external 32MB flash)
      - type: LDO
        name: ME6211
      - type: linear charger for lithium-ion batteries
        name: TP4054
      - type: battery
        name: 16340
      - type: connector
        name: USB-C
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
  - name: DIY Doorbell Circuit for Homes
    url: https://www.circuits-diy.com/diy-doorbell-circuit-for-homes-electronics-projects/
    type: maker
    year: 2022
    components:
      - type: melody generator IC
        name: UM66
      - type: speaker
        name: 8ohms speaker
  - name: Prototype to PCB by Using Autodesk Circuits
    url: https://www.instructables.com/Prototype-to-PCB-by-Using-Autodesk-Circuits/
    type: maker
    year: 2016
    components:
      - type: melody generator IC
        name: NE555N
      - type: speaker
        name: 8ohms speaker
  - name:  DIY Musical Doorbell Circuit using UM66T
    url: https://circuitdigest.com/electronic-circuits/diy-musical-doorbell-circuit-using-um66-ic
    type: maker
    year: 2021
    components:
      - type: speaker
        name: 8ohms speaker
      - type: melody generator IC
        name: UM66T
  - name: Electronic ding dong doorbell
    url: https://www.pcbway.com/project/shareproject/Electronic_ding_dong_doorbell.html
    type: maker
    year: 2020
    components:
      - type: speaker
        name: 8ohms speaker
      - type: melody generator IC
        name: IC555


references:
  - topic: Parts to consider
    list:
      - name: ESP32-C3-MINI-1-N4
        url: https://www.digikey.com/en/products/detail/espressif-systems/ESP32-C3-MINI-1-N4/13877574
        description: ESP32-C3 module with PCB antenna and 4MB flash
      - name: 16340
        url: https://www.amazon.com/LampVPath-CR123A-Battery-Holder-Mounting/dp/B07WVX74KR
        description: rechargeable lithium battery
      - name: ME6211
        url: https://www.amazon.com/ME6211C28M5G-ME6211-SOT23-5-Regulator-2-8V/dp/B09SQ8DSZ2
        description: LDO
      - name: TP4054
        url: https://www.digikey.com/en/products/detail/umw/TP4054/17635214
        description: linear charger for lithium-ion batteries
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
