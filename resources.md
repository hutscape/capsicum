---
layout: resources
title: Resources
permalink: /resources
sequence: 8

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
  - name: Seeed Studio ESP32-C3 XIAO board
    url: https://files.seeedstudio.com/wiki/XIAO_WiFi/Resources/Seeeduino-XIAO-ESP32C3-SCH.pdf
    type: maker
    year: 2022
    components:
      - type: module
        name: ESP32-C3FN4 (no on-board antenna)
      - type: LDO
        name: XC6204B33
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
  - name: Espressif ESP32-C3 DevKit M-1
    url: https://dl.espressif.com/dl/schematics/SCH_ESP32-C3-DEVKITM-1_V1_20200915A.pdf
    type: maker
    year: 2021
    components:
      - type: module
        name: ESP32-C3
      - type: connector
        name: micro USB
  - name: MakerMoeKoe picoclick C3
    url: https://github.com/makermoekoe/Picoclick-C3/blob/main/pcb/Picoclick_C3/picoclick_c3_v1.1.pdf
    type: maker
    year: 2021
    components:
      - type: module
        name: ESP32-C3
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
  - topic: Flashing ESP32-C3-WROOM-02
    list:
      - name: flashing firmware to raw ESP32-C3-wroom-02-N4 in a custom PCB
        url: https://www.esp32.com/viewtopic.php?f=12&t=34290
      - name: Esp32-c3-wroom-02 wiring module?
        url: https://forum.arduino.cc/t/esp32-c3-wroom-02-wiring-module-solved/1027662
      - name: Getting Started with ESP-WROOM-02
        url: https://learn.edwinrobotics.com/getting-started-with-esp-wroom-02/
      - name: Flashing an ESP32-WROOM ?
        url: https://www.reddit.com/r/esp32/comments/161mbvx/flashing_an_esp32wroom/
  - topic: Components to consider
    list:
      - name: ESP32-C3-MINI-1-N4
        url: https://www.digikey.com/en/products/detail/espressif-systems/ESP32-C3-MINI-1-N4/13877574
        description: ESP32-C3 module with PCB antenna and 4MB flash
      - name: ESP32-C3-WROOM-02-N4
        url: https://www.pcbway.com/components/detail/ESP32C3WROOM02N4/497176/
        description: ESP32-C3 module with PCB antenna and 4MB flash. Able to be assembled by PCBWay.
      - name: 16340 / CR123A battery holder
        url: https://www.amazon.com/LampVPath-CR123A-Battery-Holder-Mounting/dp/B07WVX74KR
        description: rechargeable lithium battery
      - name: ME6211
        url: https://www.amazon.com/ME6211C28M5G-ME6211-SOT23-5-Regulator-2-8V/dp/B09SQ8DSZ2
        description: LDO
      - name: TP4054
        url: https://www.digikey.com/en/products/detail/umw/TP4054/17635214
        description: linear charger for lithium-ion batteries
      - name: 16340
        url: https://www.battery.com.sg/product/2v-5000mah-32700-lifepo4-battery
        description: 3.2V 5000mAh rechargeable LiFePO4 battery
      - name: LiPo battery
        url: https://www.battery.com.sg/product/604460-37v-2200mah-li-po-lithium-polymer-rechargeable-battery
        description: 3.7V 2200mAh Li-po Lithium Polymer rechargeable battery
      - name: Subwoofer 8ohm Speaker
        url: https://sg.element14.com/visaton/2901/speaker-miniature-k50-8ohm/dp/4662064?MER=TARG-MER-PLP-RECO-STM71233-0
        description: 5cm 2W miniature subwoofer 8ohm speaker
      - name: Subwoofer 8ohm speaker
        url: https://www.aliexpress.com/item/1005005069433062.html
        description: 3cm 0.5W miniature subwoofer 8ohm speaker

  - topic: Snap-fit and screwless 3D-printed enclosures
    list:
      - name: Adafruit Feather Scorpio Snap Fit Case
        url: https://learn.adafruit.com/feather-scorpio-snap-fit-case/overview
      - name: Adafruit Raspberry Pi 5 3D Printed Case
        url: https://learn.adafruit.com/pi-5-case/cad-files
      - name: No-screw PCB placement in a snap fit 3D printed case
        url: https://www.youtube.com/watch?v=m_-d8xcSDQs
      - name: Simple SNAP FIT ENCLOSURE Design
        url: https://www.youtube.com/watch?v=EPpr1nilC14

  - topic: ESP32
    list:
      - name: Espressif product comparison
        url: https://products.espressif.com/#/product-comparison

  - topic: Low Power battery measurement circuit
    list:
      - name: Battery Voltage Monitoring
        url: https://electronics.stackexchange.com/questions/424627/battery-voltage-monitoring
      - name: Zero-power battery measurement
        url: https://web.archive.org/web/20230602034059/https://jeelabs.org/2013/05/18/zero-power-measurement-part-2/index.html
      - name: Low Power battery measurement switch?
        url: https://forum.arduino.cc/t/low-power-battery-measurement-switch/1171203
      - name: Picoclick-C3 schematic with battery monitoring circuit
        url: https://github.com/makermoekoe/Picoclick-C3/blob/main/pcb/Picoclick_C3/picoclick_c3_v1.1.pdf
      - name: Picoclick code for measuring battery voltage
        url: https://github.com/makermoekoe/Picoclick-C3/blob/799116efc031ff3b38fff9c742de2cf0fd753665/code/Picoclick_C3/PC3_Sender_ESPNOW_wAck/src/main.cpp#L52
---
