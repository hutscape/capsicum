#include "webhookClient.h"

WebhookClient::WebhookClient() {}

void WebhookClient::sendWebhook(
  const char* rootCA,
  const char* server,
  const char* host,
  const char* endpoint,
  int dataValue) {
  client.setCACert(rootCA);

  if (!client.connect(server, 443)) {
    Serial.println("Connection failed!");
  } else {
    Serial.println("Connected to the server");
    String data = "data1=" + String(dataValue) + "&data2=testing";
    String request = "POST " + String(endpoint) + " HTTP/1.1\r\n";
    request += "Host: " + String(host) + "\r\n";
    request += "Content-Type: application/x-www-form-urlencoded\r\n";
    request += "Content-Length: " + String(data.length()) + "\r\n\r\n";
    request += data;

    Serial.println("Sending request to the server:");
    Serial.println(request);

    client.print(request);

    // Wait for the response until 5 seconds
    unsigned long startTime = millis();
    while (client.connected() && millis() - startTime < 5000) {
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
      }
    }

    client.stop();
    Serial.println("Request sent to the server");
  }
}
