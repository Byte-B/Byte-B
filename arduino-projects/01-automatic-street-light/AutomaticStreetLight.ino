/*
  Project: Arduino-Based Automatic Street Light System
  Board: Arduino Uno
  Components: LDR, 10k ohm resistor, LED, 220 ohm resistor

  Example wiring:
  - LDR/resistor voltage-divider midpoint -> A0
  - LED anode -> D9 through 220 ohm resistor
  - LED cathode -> GND

  Depending on your voltage-divider arrangement, brighter light may produce
  a higher OR lower analog reading. Adjust LIGHT_THRESHOLD and the comparison
  direction after testing your circuit.
*/
const int LDR_PIN = A0;
const int LED_PIN = 9;
const int LIGHT_THRESHOLD = 500;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);
  Serial.print("LDR reading: ");
  Serial.println(lightLevel);

  // Assumes the analog reading gets lower as the environment gets darker.
  if (lightLevel < LIGHT_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(250);
}
