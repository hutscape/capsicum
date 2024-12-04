#define BATTERY_ENABLE_PIN 6
#define BATTERY_MEASURE_PIN 0  // ADC1_CH0, GPIO0

void setup() {
  Serial.begin(115200);
  Serial.println();

  pinMode(BATTERY_ENABLE_PIN, OUTPUT);
  digitalWrite(BATTERY_ENABLE_PIN, HIGH);
}

void loop() {
  digitalWrite(BATTERY_ENABLE_PIN, LOW);
  delayMicroseconds(10);
  int sum = 0;

  for (int i = 0; i < 100; i++) {
    sum = sum + analogRead(BATTERY_MEASURE_PIN);
  }
  float adcValue = sum / 100.0;
  Serial.print("Raw ADC Value: ");
  Serial.println(adcValue);

  delay(2000);

  digitalWrite(BATTERY_ENABLE_PIN, HIGH);

  Serial.println();
  delay(2000);
}
