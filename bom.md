---
layout: bom
title: Bill of Materials
permalink: /bom
sequence: 5
ibom: false
---

<!--

======= How to generate BOM in KiCad 7.0.8 ======

1. Click the menu item "Bulk edit fields in all schematic".
2. Ensure the BOM in KiCad has at least these columns:
    References - Will be renamed to Designator
    Qty - Quantity of each type of designator
    Value - Short name that appears on the schematic
    Footprint - KiCad's associated footprint. Will be renamed to Description
    Datasheet - URL to datasheet
    Link - Vendor URL
    Manufacturer
    MPN - Long manufacturer's part number
    Package - short consolidated name for the footprint E.g. 0603, SMD, TH
    Vendor - Name of the online site where the parts are bought from
    Category - Electronics, Connector and Mechanical later on for assembly parts
    Unit Price (USD) - Renamed to Unit. Prices in float 4 decimal places without any currency symbols
    DNP - Subset of the References / Designator column or all of them
3. Uncheck Show for the columns not required
4. Click the button at the bottom "Export as CSV"
5. Import the file to Google Docs and clean and arrange the columns in order
6. Add a column for Total price (USD) by multiplying Unit price and Qty
7. Export from Google Docs as `bill_of_materials.csv`
8. Save the CSV file in folder _data
9. Generate statistics for the BOM `make stats`
10. Check /bom URL
11. Add extra mechanical and assembly BOM items in `bill_of_materials.csv` manually
    Battery
    Antenna
    Screw, nuts, spacers
    SWD programming cable

======= How to generate interactive BOM after PCB layout ======
    1. Ensure Netlist and XML files are latest
    2. Go to PCB Layout
    3. Click iBOM menu item
    4. Change the directory in General > Directory > /hutscape/{PROJECT}/bom/
    5. Show first pin in Html default > Check "Highlight first pin"
    6. Add DNP as a column in Extra fields > Check "DNP"
    7. Generate ibom.html by clicking "Generate BOM"

====== How to generate BOM Stats file _data/bom.json ======

    1. make stats
-->
