#ifndef WIFI_CONNECTOR_H
#define WIFI_CONNECTOR_H

#include "WiFi.h"

// Uncomment the line below to enable debug prints
#define DEBUG_WIFI_CONNECTOR

// Define the timeout in milliseconds
const unsigned long TIMEOUT_MS = 2000; // 2 seconds

class WiFiConnector {
public:
  WiFiConnector(const char* ssid, const char* pass);
  void connect();
  bool isConnected();
  const char* getSSID();
  void disconnect();

private:
  const char* ssid;
  const char* pass;
};

#endif
