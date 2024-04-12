// https://raw.githubusercontent.com/espressif/arduino-esp32/990e3d5b431b63b4adc364b045a79afdad645a3f/libraries/WiFi/examples/WiFiAccessPoint/WiFiAccessPoint.ino

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

#define LED 3
#define BATTERY_ENABLE_PIN 6
// FIX: Change pin from GPIO5 (ADC2) to GPIO0 (ADC1)
// Github Issue: https://github.com/hutscape/capsicum/issues/5
#define BATTERY_MEASURE_PIN 0

const char *ssid = "batt";
const char *password = "12345678";
WiFiServer server(80);

// TODO: Add battery measurement
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  pinMode(LED, OUTPUT);
  pinMode(BATTERY_ENABLE_PIN, HIGH);

  if (!WiFi.softAP(ssid, password)) {
    log_e("Soft AP creation failed.");
    while (1) {}
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
  Serial.print("Battery Analog level: ");
  Serial.println(measureBatteryVoltage());
}

void loop() {
  WiFiClient client = server.accept();

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        digitalWrite(LED, HIGH);

        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();

        client.print("Battery Analog Level: ");
        client.println(measureBatteryVoltage());

        client.println();
        break;
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
    digitalWrite(LED, LOW);
  }
}

float measureBatteryVoltage() {
  pinMode(BATTERY_ENABLE_PIN, LOW);
  delay(1000);

  int sum = 0;
  for (int i = 0; i < 100; i++) {
    sum = sum + analogRead(BATTERY_MEASURE_PIN);
  }
  float mean = sum/100.0;
  float adcValue = mean * (1.1 / 4096.0);
  float batteryVoltage = adcValue * 11.0;
  // TODO: Fix schematic to use 10k instead of 100k

  digitalWrite(BATTERY_ENABLE_PIN, HIGH);

  return batteryVoltage;
}
