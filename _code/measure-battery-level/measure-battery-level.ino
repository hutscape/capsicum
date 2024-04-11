// https://raw.githubusercontent.com/espressif/arduino-esp32/990e3d5b431b63b4adc364b045a79afdad645a3f/libraries/WiFi/examples/WiFiAccessPoint/WiFiAccessPoint.ino

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

#define BATTERY_ENABLE_PIN 6
#define BATTERY_MEASURE_PIN 5

const char *ssid = "batt";
const char *password = "12345678";
WiFiServer server(80);

// TODO: Add battery measurement
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  if (!WiFi.softAP(ssid, password)) {
    log_e("Soft AP creation failed.");
    while (1) {}
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.accept();

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();
        client.print("hello world");
        client.println();
        break;
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

float measureBatteryVoltage() {
  pinMode(BATTERY_ENABLE_PIN, OUTPUT);
  digitalWrite(BATTERY_ENABLE_PIN, HIGH);

  delay(100);

  int rawValue = analogRead(BATTERY_MEASURE_PIN);
  // TODO: Fix schematic to use 10k instead of 100k
  float voltage = rawValue * (3.3 / 4095);

  digitalWrite(BATTERY_ENABLE_PIN, LOW);

  return voltage;
}
