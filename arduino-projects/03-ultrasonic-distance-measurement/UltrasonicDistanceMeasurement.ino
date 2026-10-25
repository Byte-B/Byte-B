/*
  Project: Arduino-Based Ultrasonic Distance Measurement System
  Board: Arduino Uno
  Sensor: HC-SR04

  Wiring: VCC -> 5V, GND -> GND, TRIG -> D9, ECHO -> D10.
*/
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const unsigned long ECHO_TIMEOUT_US = 30000UL;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  digitalWrite(TRIG_PIN, LOW);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT_US);

  if (duration == 0) {
    Serial.println("No echo received; check wiring or target distance.");
  } else {
    // Approximate speed of sound: 0.0343 cm/us. Divide by 2 for round trip.
    float distanceCm = (duration * 0.0343) / 2.0;
    Serial.print("Distance: ");
    Serial.print(distanceCm, 1);
    Serial.println(" cm");
  }
  delay(300);
}
