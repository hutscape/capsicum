#ifndef WIFI_CONNECTOR_H
#define WIFI_CONNECTOR_H

#include "WiFi.h"

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
