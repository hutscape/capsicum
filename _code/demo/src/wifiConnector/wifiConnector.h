#ifndef WIFI_CONNECTOR_H
#define WIFI_CONNECTOR_H

#include "WiFi.h"

// Uncomment the line below to enable debug prints
#define DEBUG_WIFI_CONNECTOR

class WiFiConnector {
public:
  WiFiConnector(const char* ssid, const char* pass);
  void connect();
  bool isConnected();
  const char* getSSID();

private:
  const char* ssid;
  const char* pass;
};

#endif
