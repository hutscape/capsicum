---
layout: pcb
title: PCB
permalink: /pcb
sequence: 3

three_d: true
pcb_layout: true
gerber: true

# maximum number of images prototype-n.jpg in folder images/pcb/prototype
max_prototype_images: 7

manufacturing_params_image: pcbway.png
manufacturing_params:
  - name: "Manufacturer"
    value: "PCBWay"
  - name: Build time
    value: "4 days"
  - name: "Size"
    value: "70 x 55 mm"
  - name: "Layers"
    value: "2"
  - name: "PCB Thickness"
    value: "1.6 mm"
  - name: "Min hole size:"
    value: "0.3 mm"
  - name: "Silkscreen"
    value: "White"
  - name: "Surface Finish"
    value: "HASL lead free"
  - name: "Via process"
    value: "Tenting vias"
  - name: "Date code"
    value: "None"
  - name: "Quantity"
    value: "5"
  - name: "PCB Material"
    value: "FR-4: TG130"
  - name: "Min track/spacing"
    value: "6/6mil"
  - name: "Solder Mask"
    value: "Black"
  - name: "Edge connector"
    value: "No"
  - name: "HASL to ENIG"
    value: "No"
  - name: "Finished Copper"
    value: "1oz Cu"
  - name: "UL marking"
    value: "No"
---

<!-- display the comments in markdown, but not when rendered -->
<!-- markdownlint-disable MD033 -->

<!-- Steps to update hardware

Schematic in KiCad:
1. Change issue date and revision of the schematic:
    File > Page Settings > Issue Date
    File > Page Settings > Revision
1. Create a schematic PDF file `schematic.pdf`
    File > Print > Check Print sheet reference and title block > Print > Save as PDF > Title : Project name > Save in pcb/docs/schematic.pdf
1. Create a schematic PNG file `schematic.png`
    Open schematic.pdf in Preview > Format: PNG > Resolution 300 > schematic.png > images/pcb/schematic.png

PCB Layout in KiCad:
1. Change version number and date in layout Silscreen
1. Change revision and issue date of the layout:
    File > Page Settings > Issue Date
    File > Page Settings > Revision
1. Create a layout PDF file `layout.pdf`
    File > Print > Check
      - `F.Cu`, `B.Cu`,
      - `F.Paste`, `B.Paste`
      - `F.SilkScreen`, `B.SilkScreen`,
      - `F.Mask`, `B.Mask`,
      - `User.Drawings`,
      - `Edge.Cuts`,
      - `F.Courtyard`, `B.Courtyard`,
      - `F.Fab`, `B.Fab`
    > Save as PDF > Title : Project name >  Save in pcb/docs/layout.pdf
1. Create front layer screenshot of `layout-front.png`
    View > Uncheck Show Grid > Enable all Front layers > Disable F.Fab > Select Silscreen layer > Take a screenshot
1. Create back layer screenshot `layout-back.png`
    View > Uncheck Show Grid > Enable all Back layers > Disable B.Fab > Select Silscreen layer > Flip view for Back layer > Take a screenshot
1. Create screenshots of the 3D view
    - 3dview-back.png
    - 3dview-bottom.png
    - 3dview-front.png
    - 3dview-side1.png
    - 3dview-side2.png
    - 3dview-side3.png
    - 3dview-side4.png
    - 3dview-top.png
    - layout-back.png
    - layout-front.png

[Optional for manufacturing and post-manufacturing]
Gerbers: https://www.pcbway.com/blog/help_center/How_to_Generate_Gerber_and_Drill_Files_in_KiCad_7_0_ab0d12bb.html
Position file: https://www.pcbway.com/blog/help_center/Generate_Position_File_in_Kicad.html

Generate Gerbers:
1. File > "Fabrication Outputs" -> "Gerbers (.gbr)"
1. Output directory: `gerbers/`
1. Include layers:
    - F.Cu
    - B.Cu
    - F.Paste
    - B.Paste
    - F.SilkScreen
    - B.SilkScreen
    - F.Mask
    - B.Mask
    - Edge.Cuts
    - F.Courtyard
    - B.Courtyard
    - F.Fab
    - B.Fab
1. Check boxes in General Options
    - Plot reference designators
    - Check zone fills before plotting
    - Substract soldermask from silkscreen
1. Click "Plot"
1. Check the gerber files `*.gbr` in `gerbers` folder

Generate Drill Files:
1. Click "Generate Drill Files"
    1. Drill file format: Excellon > Oval holes Drill Mode: User route command (Recommended)
    1. Drill origin > Absolute
    1. Drill units > Millimeters
    1. Zeros Format > Decimal format (recommended)
    1. Map file format > Postscript
1. Click "Generate Drill Files"
1. Close the dialog
1. Check the drill files `*.drl` in `gerbers` folder

Generate Position file:
1. Place > Drill / File origin
1. File > Fabrication Outputs > Component placement (.pos)
1. Output directory: `gerbers/`
1. Click "Generate Position File"
1. Check *.pos file in `gerbers` folder

Compress and ZIP the `gerbers` folder and create a git tag with the version number.
1. Rename `gerbers` zip folder to project-gerbers-V1.0.0.zip
1. Create a git tag with the version number
    ```
    git tag -a V1.0.0 -m "Release V1.0.0"
    ```
1. Push the tag to the remote repository
    ```
    git push origin V1.0.0
    ```
-->
