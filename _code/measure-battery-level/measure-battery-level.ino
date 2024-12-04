#define LED 3
#define BATTERY_ENABLE_PIN 6
#define BATTERY_MEASURE_PIN 0

const int adcMax = 4095;  // 12-bit ADC resolution

// https://forum.arduino.cc/t/esp32-c3-adc-issue-reading-4095-at-2-8v/1127687/7
const float Vref = 2.86;  // Reference voltage for ADC (2.8V for ESP32-C3)

void setup() {
  Serial.begin(115200);
  Serial.println();

  pinMode(LED, OUTPUT);
  pinMode(BATTERY_ENABLE_PIN, OUTPUT);
  digitalWrite(BATTERY_ENABLE_PIN, HIGH);
}

void loop() {
  digitalWrite(LED, HIGH);

  digitalWrite(BATTERY_ENABLE_PIN, LOW);
  delayMicroseconds(10);
  int sum = 0;

  for (int i = 0; i < 100; i++) {
    sum = sum + analogRead(BATTERY_MEASURE_PIN);
  }
  float adcValue = sum / 100.0;
  Serial.print("Raw ADC Value: ");
  Serial.println(adcValue);

  float voltageAtPin = (adcValue / adcMax) * Vref;
  Serial.print("Voltage at Pin: ");
  Serial.print(voltageAtPin);
  Serial.println("V");

  float batteryVoltage = voltageAtPin * 0.5;  // 0.5 is the voltage divider ratio
  Serial.print("Battery Voltage: ");
  Serial.print(batteryVoltage);
  Serial.println("V");

  // 3.0: Minimum voltage of the battery
  // 4.2: Maximum voltage of the battery
  // 100: Maximum battery level in percentage
  float batteryLevel = (batteryVoltage - 3.0) / (4.2 - 3.0) * 100;
  Serial.print("Battery Level: ");
  Serial.print(batteryLevel);
  Serial.println("%");

  delay(2000);

  digitalWrite(BATTERY_ENABLE_PIN, HIGH);
  digitalWrite(LED, LOW);

  Serial.println();
  delay(2000);
}
