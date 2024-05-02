---
layout: csq
title: CSQ
permalink: /csq
sequence: 7

# Schedule
design_start: '2023-10-01'
design_end: '2024-02-29'
manufacturing_start: '2024-03-01'
manufacturing_end: '2024-03-21'
manufacturing_end: '2024-03-21'
integration_start: '2024-03-22'
progress:
  - month: April 2024
    details: Board bring-up and debug of the first prototype PCB
  - month: March 2024
    details: Send for manufacturing and assembly of 2 prototypes. This phase includes PCB manufacturing, component procurement, pick and place, 3D printing the cases.
  - month: December 2023
    details: Completing the schematics with footprints, MPN and availability of assembly parts.

# Quality
lessons:
  - title: V2.0
    subtitle: Improvements for the next version
    list:
      - name: (Layout) Use <a href="https://docs.kicad.org/8.0/en/pcbnew/pcbnew.html">teardrops</a> in KiCAD 8.0
      - name: (Layout) Add <a href="https://youtu.be/g4m91gv-4oQ?t=1088">fudicial markers</a> for pick and place
      - name: (Case) Add more rounded corners and chamfers for <a href="https://www.pinterest.com/sayanee/product-design/">timeless product design</a> enclosures
      - name: (Case) Following DFA (Design for Assmebly), make the case easier to assemble by creating assymetric screw hole positions on the PCB and case
      - name: (Schematic) Use a <a hreaf="https://github.com/makermoekoe/Picoclick-C3/blob/main/pcb/Picoclick_C3T/picoclick_c3t_v1_bom.csv#L18">single RGB LED</a> for status indication
      - name: (Schematic) Add <a href="https://forum.kicad.info/t/understanding-multi-sheet-schematics/42922/2">multi sheet schematics</a> for better readability
      - name: (Schematic) Add component images and parameter graphs <a href="https://github.com/EPFLXplore/XRE_LeggedRobot_HW/blob/master/amulet_controller/Schematic/amulet_controller.pdf">for better understanding</a>
      - name: (Firmware) Use <a href="https://github.com/arduino-libraries/Arduino_ESP32_OTA">OTA updates</a> for firmware
      - name: (BOM) Use a better quality <a href="https://www.digikey.com/en/products/detail/nidec-components-corporation/CL-SB-22A-11T/3507836">slide switch DPDT</a> for <a href="https://www.nordicsemi.com/Products/Development-hardware/Power-Profiler-Kit-2/Download#infotabs">better tactile feedback</a>
      - name: (Schematic) Add a switch to turn on and off wireless communication to fallback to legacy functionality
      - name: (BOM) Add a header male pin (GND and VUSB/VBAT) to use with nRF profiler for power consumption measurements
      - name: (Case) Make the text height bigger for LEDs and ON/OFF power switch
      - name: (Case) Add more chamfers and rounded corners for a better aesthetic
      - name: (Case) <strong>Teeth and groves</strong> - Make the teeth thicker for better strength
      - name: (Case) <strong>Teeth and groves</strong> - Add holder in the teeth to that the top and bottom case do not slide
      - name: (Case) <strong>Teeth and grooves</strong> - Include visual cues on the exterior for finger placement
      - name: (Case) PCB holder screw lug can be shorter
      - name: (Case) Add an LED slot to view the charge LED from the outside without opening the case
      - name: (Power) <strong>Battery</strong> - Use flat LiPo battery for a compact design
      - name: (Layout) <strong>PCB</strong> - Add silkscreen pin labels for all connectors that extend outside the PCB E.g. pin headers or USB-C
      - name: Use Conventional Commit Messages for <a href="https://www.conventionalcommits.org/en/v1.0.0/">better git history</a> with scopes such as schematic, layout, bom, firmware, case, power.
---
