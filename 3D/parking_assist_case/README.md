# Arduino Case 1

## Overview

## Specs

**3D Model**
[Tinkurcad](https://www.tinkercad.com/things/5iqU6QGvB0J-copy-of-tinkur-parking-assist-case/editv2)

**STL**
See STL file in this directory

**Slice / Print Settings**
See Simplify 3D FFF file in this directory

**Printer**
Anycubic Kossel Liner Plus

**Filanment**
Hatchbox PLA 1.75mm

## Notes

* v1
    - https://www.tinkercad.com/things/5uq7JSA6oC3-tinkur-parking-assist-case based on remix of another Arduino case
    - Validated Arduino scew hole placement.  Openings for power and USB were too low.  Top slide in track for lid didn't print correctly; likely needed supports.
* v2
    - updated https://www.tinkercad.com/things/5uq7JSA6oC3-tinkur-parking-assist-case.  Moved openings for power and USB.  Added supports using Mesh Mixer.  Added openings for ultrasonic sensors.  
    - Fixed power and USB placement.  Openings for ultrasonic sensors too close by 2mm.  Mesh Mixer supports didn't print well; not all of them adhered to the base; maybe too thin at bottom.
* v3
    - updated https://www.tinkercad.com/things/5uq7JSA6oC3-tinkur-parking-assist-case.  Fixed openings for ultrasonic sensors.  Added opening for LED light.  Switched to Simplify 3D for slicing / supports / printing.
    - Simplify 3D slow default print settings but great quality.  Supports were awesome - generated where needed and not where no needed.  Also easy to add / modify supports.  Also super easy to remove supports; only needed pliers to remove one and only because it was touch to get to with my fingers.  Raft was a bit hard to remove.  Will try printing without for now and adjusting setting later for nother part.  Increasing brim width to compensate for removing raft.  Also there was a bit of warping so perhaps larger brim will help with that too; could also have been the print head being too far away from print bed.
* v4
    - started a new v2 model https://www.tinkercad.com/things/5iqU6QGvB0J-tinkur-parking-assist-case-v2.  Simplified design, removing a ton of combined parts to reduce likelyhood of measurement / combine errors.  Also switch top design from slide in to clip on to reduce need for long wires to connect ultrasonic sensor and led to Arduino.  Increased side of LED hole by 2mm to allow better seating.
    - MVP.  Lid snaps in place well.  Made a mistake for ultrasonic sensor hole size but resulted in the sensor tension mounting which is awesome. 
     






