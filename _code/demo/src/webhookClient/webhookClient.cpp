#include "webhookClient.h"

WebhookClient::WebhookClient() {}

bool WebhookClient::sendWebhook(
  const char* rootCA,
  const char* server,
  const char* host,
  const char* endpoint,
  int dataValue) {
  client.setCACert(rootCA);

  if (!client.connect(server, 443)) {
    return false;
  } else {
    // TODO: Change the data2 to be production
    // TODO: Change the data1 to be battery level
    String data = "data1=" + String(dataValue) + "&data2=testing";
    String request = "POST " + String(endpoint) + " HTTP/1.1\r\n";
    request += "Host: " + String(host) + "\r\n";
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
