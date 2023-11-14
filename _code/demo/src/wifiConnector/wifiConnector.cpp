#include "WiFiConnector.h"

WiFiConnector::WiFiConnector(const char* ssid, const char* pass) : ssid(ssid), pass(pass) {}

void WiFiConnector::connect() {
  WiFi.useStaticBuffers(true);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  // TODO(sayanee): Add a timeout for trying to connect to WiFi
  #ifdef DEBUG_WIFI_CONNECTOR
    Serial.println("Connecting to WiFi");
  #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    #ifdef DEBUG_WIFI_CONNECTOR
      Serial.print(".");
    #endif
  }
}

bool WiFiConnector::isConnected() {
  return WiFi.status() == WL_CONNECTED;
}

const char* WiFiConnector::getSSID() {
  if (WiFi.status() == WL_CONNECTED) {
    return ssid;
  } else {
    return "Not connected";
  }
}
