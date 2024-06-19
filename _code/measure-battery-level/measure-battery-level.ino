// The code turns ON the MOSFET for 2 seconds
// and then turns it OFF for 2 seconds.
// The LED is also turned ON and OFF to indicate the state of the MOSFET.
// The serial monitor is used to print the state of the MOSFET.

#define LED 3
#define BATTERY_ENABLE_PIN 6
#define BATTERY_MEASURE_PIN 0

const float R1 = 10000.0;  // 10kΩ
const float R2 = 100000.0;  // 100kΩ
const float Vref = 3.3;  // Reference voltage for ADC (3.3V for ESP32-C3)
const int ADCmax = 4095;  // 12-bit ADC resolution


void setup() {
  Serial.begin(115200);
  Serial.println();

  pinMode(LED, OUTPUT);
  pinMode(BATTERY_ENABLE_PIN, OUTPUT);
  digitalWrite(BATTERY_ENABLE_PIN, HIGH);  // Turn OFF the MOSFET
}

void loop() {
  digitalWrite(BATTERY_ENABLE_PIN, LOW);  // Turn ON the MOSFET
  digitalWrite(LED, HIGH);
  Serial.println("MOSFET is ON");

  delayMicroseconds(10);
  int sum = 0;
  for (int i = 0; i < 100; i++) {
    sum = sum + analogRead(BATTERY_MEASURE_PIN);
  }

  float adcValue = sum / 100.0;
  Serial.print("Raw ADC Value: ");
  Serial.println(adcValue);

  float voltageAtPin = (adcValue / ADCmax) * Vref;
  Serial.print("Voltage at Pin: ");
  Serial.println(voltageAtPin);

  float batteryVoltage = voltageAtPin * ((R1 + R2) / R2);
  Serial.print("Battery Voltage: ");
  Serial.println(batteryVoltage);

  digitalWrite(BATTERY_ENABLE_PIN, HIGH);  // Turn OFF the MOSFET
  digitalWrite(LED, LOW);
  Serial.println("MOSFET is OFF");
  Serial.println("-------------------- ");
  delay(4000);
}
