#ifndef WEBHOOK_CLIENT_H
#define WEBHOOK_CLIENT_H

#include <WiFiClientSecure.h>

// Uncomment the line below to enable debug prints
#define DEBUG_WEBHOOK_CLIENT

class WebhookClient {
private:
  WiFiClientSecure client;

public:
  WebhookClient();
  bool sendWebhook(
    const char* rootCA,
    const char* server,
    const char* host,
    const char* endpoint,
    int dataValue);
};

#endif
