// https://raw.githubusercontent.com/espressif/arduino-esp32/990e3d5b431b63b4adc364b045a79afdad645a3f/libraries/WiFi/examples/WiFiAccessPoint/WiFiAccessPoint.ino

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

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
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("hello world");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
