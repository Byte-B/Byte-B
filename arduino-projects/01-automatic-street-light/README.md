# Arduino-Based Automatic Street Light System

## Overview
An Arduino Uno reads an LDR (Light Dependent Resistor) and switches an LED on when the measured light level crosses a configurable threshold.

## Components
- Arduino Uno
- LDR
- 10 kΩ resistor for the voltage divider
- LED and 220 Ω current-limiting resistor
- Breadboard and jumper wires

## Example wiring
- LDR/resistor voltage-divider midpoint → `A0`
- LED anode → `D9` through a 220 Ω resistor
- LED cathode → `GND`
- Connect the LDR and 10 kΩ resistor as a voltage divider between `5V` and `GND`.

The divider arrangement determines whether the reading rises or falls in bright light. Check the Serial Monitor and adjust the comparison in the sketch for your circuit.

## Run
1. Open `AutomaticStreetLight.ino` in Arduino IDE.
2. Select Arduino Uno and the correct port.
3. Upload the sketch.
4. Open Serial Monitor at 9600 baud.
5. Test in bright and dim conditions and tune `LIGHT_THRESHOLD`.

## How it works
The Arduino reads the LDR voltage at `A0`. If the reading is below the configured threshold, it turns the LED on; otherwise, it turns it off.

## Safety and limitations
This is a low-voltage LED prototype, not a mains-powered street-light controller. Never connect household mains voltage directly to an Arduino circuit. Add hysteresis or averaging to reduce flicker around the threshold.

## Project status
Starter implementation based on the resume description. Test and tune with the actual circuit before claiming measured performance.
