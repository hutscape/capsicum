#include "webhookClient.h"

WebhookClient::WebhookClient() {}

bool WebhookClient::sendWebhook(
  const WebhookClientConfig* config) {
  client.setCACert(config->rootCA);

  if (!client.connect(config->server, 443)) {
    return false;
  } else {
    String data = "data1="
      + String(config->batteryLevel)
      + "&data2="
      + String(config->environment);
    String request = "POST " + String(config->endpoint) + " HTTP/1.1\r\n";
    request += "Host: " + String(config->host) + "\r\n";
    request += "Content-Type: application/x-www-form-urlencoded\r\n";
    request += "Content-Length: " + String(data.length()) + "\r\n\r\n";
    request += data;

    #ifdef DEBUG_WEBHOOK_CLIENT
      Serial.println(request);
    #endif
    client.print(request);

    // Wait for the response until 5 seconds
    unsigned long startTime = millis();
    while (client.connected() && millis() - startTime < 5000) {
      if (client.available()) {
        char c = client.read();
        #ifdef DEBUG_WEBHOOK_CLIENT
        Serial.print(c);
        #endif
      }
    }

    client.stop();
    return true;
  }
}
