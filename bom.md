---
layout: bom
title: Bill of Materials
permalink: /bom
sequence: 4
ibom: true
---

<!-- KiCad 7.0.8

======= How to generate BOM  ======

1. Click the menu item "Bulk edit fields in all schematic".
2. Ensure the BOM in KiCad has at least these columns:
    References - Will be renamed to Designator
    Value - Short name that appears on the schematic
    Footprint - KiCad's associated footprint. Will be renamed to Description
    Datasheet - URL to datasheet
    Category - Electronics, Connector and Mechanical later on for assembly parts
    DNP - Subset of the References / Designator column or all of them
    Link - Vendor URL
    Manufacturer
    MPN - Long manufacturer's part number
    Package - short consolidated name for the footprint E.g. 0603, SMD, TH
    Unit Price (USD) - Renamed to Unit. Prices in float 4 decimal places without any currency symbols
    Vendor - Name of the online site where the parts are bought from
    Qty - Quantity of each type of designator
3. Uncheck Show for the columns not required
4. Click the button at the bottom "Export as CSV"
5. Import the file to Google Spreadsheet sheet name "raw data from KiCad"
6. Check sheets "BOM" and "Summary" are updated
7. Shorten DNP column to the Designator E.g. JP1-JP4 to become "DNP all" in "BOM" sheet
8. File > Download > CSV the "BOM" sheet
9. Rename CSV to bill_of_materials.csv
9. Transfer the file to _data
10. Edit file _data/stats.json with data from "Stats" sheet
11. Check /bom URL
12. Add extra mechanical and assembly BOM items in `bill_of_materials.csv` manually
    Battery
    Antenna
    Screw, nuts, spacers
    SWD programming cable

======= Generate interactive BOM after PCB layout ======


    1. [Install](https://github.com/openscopeproject/InteractiveHtmlBom/wiki/Installation) [InteractiveHtmlBom plugin](https://github.com/openscopeproject/InteractiveHtmlBom) in KiCad's plugin manager
    2. Go to PCB Editor
    3. Click iBOM menu item
    4. Change the directory in General > Directory > /hutscape/{PROJECT}/bom/
    5. Show first pin in Html default > Check "Highlight first pin"
    6. Show and Group DNP as a column in Fields > Check "DNP"
    7. Generate ibom.html by clicking "Generate BOM"
    8. Enable iBom display in bom.md meta data ibom: true
    9. Start the website server with "make" and check /bom/#interactive-bom URL


====== How to generate BOM Stats file _data/bom.json ======

    1. make stats
-->
