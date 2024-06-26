// This code sets up an ESP32-C3 as an access point (AP) with a specified SSID and password.
// It creates a server that listens for incoming client connections on port 80.
// When a client connects, it sends a "Hello World!" message as the response.
// The code also includes a LED that turns on when a client is connected and turns off when the client disconnects.

// This code is based on the WiFiAccessPoint example from the Arduino ESP32 library:
// https://raw.githubusercontent.com/espressif/arduino-esp32/990e3d5b431b63b4adc364b045a79afdad645a3f/libraries/WiFi/examples/WiFiAccessPoint/WiFiAccessPoint.ino

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

#define LED 3

const char *ssid = "batt";
const char *password = "12345678";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  pinMode(LED, OUTPUT);

  if (!WiFi.softAP(ssid, password)) {
    Serial.println("Soft AP creation failed.");
    while (1) {}
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}

void handleClient(WiFiClient client) {
  Serial.println("New Client.");
  String currentLine = "";
  while (client.connected()) {
    if (client.available()) {
      digitalWrite(LED, HIGH);

      client.println("HTTP/1.1 200 OK");
      client.println("Content-type:text/html");
      client.println();

      client.print("Hello World!");

      client.println();
      break;
    }
  }
  client.stop();
  Serial.println("Client Disconnected.");
  digitalWrite(LED, LOW);
}

void loop() {
  WiFiClient client = server.accept();

  if (client) {
    handleClient(client);
  }
}
