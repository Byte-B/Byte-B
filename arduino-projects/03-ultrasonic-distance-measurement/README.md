# Arduino-Based Ultrasonic Distance Measurement System

## Overview
Uses an HC-SR04 ultrasonic sensor and Arduino Uno to estimate the distance to a nearby object and print it to the Serial Monitor.

## Components
- Arduino Uno
- HC-SR04 ultrasonic sensor
- Breadboard and jumper wires
- Optional LED and suitable current-limiting resistor for extensions

## Wiring
- HC-SR04 `VCC` → Arduino `5V`
- HC-SR04 `GND` → Arduino `GND`
- HC-SR04 `TRIG` → digital pin `D9`
- HC-SR04 `ECHO` → digital pin `D10`

## Run
1. Open `UltrasonicDistanceMeasurement.ino` in Arduino IDE.
2. Select Arduino Uno and the correct port.
3. Upload the sketch.
4. Open Serial Monitor at 9600 baud.
5. Place an object in front of the sensor and observe the distance.

## Calculation
The echo pulse duration is the round-trip travel time of the sound wave. Using an approximate sound speed of 0.0343 cm/µs:

`distance (cm) = echo duration (µs) × 0.0343 / 2`

The division by two accounts for the sound traveling to the object and back.

## Troubleshooting
- Check common ground and TRIG/ECHO pin assignments.
- Keep the target within the sensor's practical range; soft or angled surfaces can affect readings.
- The sketch reports a timeout if no echo is received.

## Project status
Starter implementation based on the resume description. Test against measured distances before claiming accuracy.
