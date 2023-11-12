#ifndef WEBHOOK_CLIENT_H
#define WEBHOOK_CLIENT_H

#include <WiFiClientSecure.h>

class WebhookClient {
private:
  WiFiClientSecure client;

public:
  WebhookClient();
  void sendWebhook(
    const char* rootCA,
    const char* server,
    const char* host,
    const char* endpoint,
    int dataValue);
};

#endif
