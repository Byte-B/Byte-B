# Arduino-Based Temperature Monitoring System

## Overview
Reads an LM35 analog temperature sensor using an Arduino Uno and prints the estimated temperature in degrees Celsius to the Serial Monitor.

## Components
- Arduino Uno
- LM35 temperature sensor
- Breadboard and jumper wires

## Example wiring
Check the datasheet for your exact LM35 package before powering it:
- Sensor supply (+Vs) → `5V`
- Sensor output (Vout) → `A0`
- Sensor ground (GND) → Arduino `GND`

## Run
1. Open `TemperatureMonitoring.ino` in Arduino IDE.
2. Select Arduino Uno and the correct port.
3. Upload the sketch.
4. Open Serial Monitor at 9600 baud.
5. Observe ADC reading, estimated voltage, and temperature.

## Calculation
For the assumed 5 V ADC reference:
- `voltage = ADC reading × 5.0 / 1023`
- LM35 output is nominally 10 mV/°C, so `temperature °C = voltage × 100`

## Accuracy notes
The calculation assumes a 5.0 V ADC reference. Actual reference voltage, sensor tolerance, wiring, and noise can affect readings. Measure the reference voltage or calibrate the system for better accuracy.

## Project status
Starter implementation based on the resume description. Compare readings with a trusted thermometer before reporting accuracy.
