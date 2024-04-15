// The code turns ON the MOSFET for 2 seconds
// and then turns it OFF for 2 seconds.
// The LED is also turned ON and OFF to indicate the state of the MOSFET.
// The serial monitor is used to print the state of the MOSFET.

#define LED 3
#define BATTERY_ENABLE_PIN 6
#define BATTERY_MEASURE_PIN 0

void setup() {
  Serial.begin(115200);
  Serial.println();

  pinMode(LED, OUTPUT);
  pinMode(BATTERY_ENABLE_PIN, OUTPUT);
}

void loop() {
  // FIX: BATTERY_ENABLE_PIN voltage does not change whether it is HIGH or LOW
  pinMode(BATTERY_ENABLE_PIN, LOW);  // Turn ON the MOSFET
  digitalWrite(LED, HIGH);
  Serial.print("MOSFET is ON");
  delay(2000);

  pinMode(BATTERY_ENABLE_PIN, HIGH);  // Turn OFF the MOSFET
  digitalWrite(LED, LOW);
  Serial.print("MOSFET is OFF");
  delay(2000);
}
