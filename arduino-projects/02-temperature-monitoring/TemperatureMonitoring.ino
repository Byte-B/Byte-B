/*
  Project: Arduino-Based Temperature Monitoring System
  Board: Arduino Uno
  Sensor: LM35 analog temperature sensor

  Verify your exact sensor package pinout against its datasheet.
  Typical connections: +Vs -> 5V, Vout -> A0, GND -> GND.
  LM35 output is nominally 10 mV per degree Celsius.
*/
const int LM35_PIN = A0;
const float ADC_REFERENCE_VOLTAGE = 5.0;
const int ADC_MAX_VALUE = 1023;

void setup() {
  Serial.begin(9600);
  Serial.println("LM35 Temperature Monitor");
}

void loop() {
  int adcValue = analogRead(LM35_PIN);
  float voltage = adcValue * (ADC_REFERENCE_VOLTAGE / ADC_MAX_VALUE);
  float temperatureC = voltage * 100.0;

  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V | Temperature: ");
  Serial.print(temperatureC, 1);
  Serial.println(" C");

  delay(1000);
}
