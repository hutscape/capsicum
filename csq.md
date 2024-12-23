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
  - name: (Schematic) Use a <a hreaf="https://github.com/makermoekoe/Picoclick-C3/blob/main/pcb/Picoclick_C3T/picoclick_c3t_v1_bom.csv#L18">single RGB LED</a> for status indication
  - name: (Schematic) Add <a href="https://forum.kicad.info/t/understanding-multi-sheet-schematics/42922/2">multi sheet schematics</a> for better readability
  - name: (Schematic) Add component images and parameter graphs <a href="https://github.com/EPFLXplore/XRE_LeggedRobot_HW/blob/master/amulet_controller/Schematic/amulet_controller.pdf">for better understanding</a>
  - name: (Schematic) Add a switch to turn on and off wireless communication to fallback to legacy functionality
  - name: (Layout) Use <a href="https://docs.kicad.org/8.0/en/pcbnew/pcbnew.html">teardrops</a> in KiCAD 8.0
  - name: (Layout) Add <a href="https://youtu.be/g4m91gv-4oQ?t=1088">fudicial markers</a> for pick and place
  - name: (Layout) <strong>PCB</strong> - Add silkscreen pin labels for all connectors that extend outside the PCB E.g. pin headers or USB-C
  - name: (Layout, Case) <a href="https://www.fiveflute.com/guide/design-for-assembly-dfa-best-practices/">Mistake proof assembly</a> by designing the case and PCB to fit only one way, E.g.asymmetric screw holes, PCB shape and screw lugs
  - name: (Layout) Add a header male pin (GND and VUSB/VBAT) to use with nRF profiler for power consumption measurements
  - name: (BOM) Use a better quality <a href="https://www.digikey.com/en/products/detail/nidec-components-corporation/CL-SB-22A-11T/3507836">slide switch DPDT</a> for <a href="https://www.nordicsemi.com/Products/Development-hardware/Power-Profiler-Kit-2/Download#infotabs">better tactile feedback</a>
  - name: (Case) Make the text height bigger for LEDs and ON/OFF power switch
  - name: (Case) Add more chamfers and rounded corners for a better aesthetic
  - name: (Case) <strong>Teeth and groves</strong> - Make the teeth thicker for better strength
  - name: (Case) <strong>Teeth and groves</strong> - Add holder in the teeth to that the top and bottom case do not slide
  - name: (Case) <strong>Teeth and grooves</strong> - Include visual cues on the exterior for finger placement
  - name: (Case) PCB holder screw lug can be shorter
  - name: (Case) Add an LED slot to view the charge LED from the outside without opening the case
  - name: (Case) Add <a href="https://www.pollen.am/design_for_3d_printing_edges_fillets_ribs/">filletted poles</a> for screw lugs and holders on the case base
  - name: (Case) Ensure charging LED is visible from the outside through a slot or a transparent window
  - name: (Case) Ensure charging cable position on the case is accessible to the power socket on-site for charging
  - name: (Case) Add more rounded corners and chamfers for <a href="https://www.pinterest.com/sayanee/product-design/">timeless product design</a> enclosures
  - name: (Case) Following DFA (Design for Assmebly), make the case easier to assemble by creating assymetric screw hole positions on the PCB and case
  - name: (Firmware) Use <a href="https://github.com/arduino-libraries/Arduino_ESP32_OTA">OTA updates</a> for firmware
  - name: (Power) <strong>Battery</strong> - Use flat LiPo battery for a compact design
  - name: (Chore) Use Conventional Commit Messages for <a href="https://www.conventionalcommits.org/en/v1.0.0/">better git history</a> with scopes such as firmware, case, schematic, layout, docs, bom, power, design, website, chore (CI/CD/updates).
---
