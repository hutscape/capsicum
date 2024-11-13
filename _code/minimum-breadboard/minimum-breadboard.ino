#define LED LED_BUILTIN
#define BELL_PIN 7
#define WAKEUP_INTERRUPT_PIN 4
RTC_DATA_ATTR int bootCount = 0;

void setup() {
  ++bootCount;
  Serial.begin(115200);

  Serial.println("Boot number: " + String(bootCount));

  // ring the bell
  Serial.println("Ringing the bell");
  pinMode(BELL_PIN, OUTPUT);
  digitalWrite(BELL_PIN, HIGH);
  delay(1000);
  digitalWrite(BELL_PIN, LOW);

  print_wakeup_reason();

  // blink the LED 10 times to indicate that the device is awake
  pinMode(LED, OUTPUT);
  for (int i = 0; i < 10; ++i) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }

  // go to deep sleep
  Serial.println("Going to deep sleep now");

  esp_deep_sleep_enable_gpio_wakeup(1 << WAKEUP_INTERRUPT_PIN,
    ESP_GPIO_WAKEUP_GPIO_HIGH);
  esp_deep_sleep_start();
}

void loop() { }

void print_wakeup_reason() {
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch (wakeup_reason) {
    case ESP_SLEEP_WAKEUP_EXT0:
      Serial.println("Wakeup caused by external signal using RTC_IO");
      break;
    case ESP_SLEEP_WAKEUP_EXT1:
      Serial.println("Wakeup caused by external signal using RTC_CNTL");
      break;
    case ESP_SLEEP_WAKEUP_TIMER:
      Serial.println("Wakeup caused by timer");
      break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD:
      Serial.println("Wakeup caused by touchpad");
      break;
    case ESP_SLEEP_WAKEUP_ULP:
      Serial.println("Wakeup caused by ULP program");
      break;
    default:
      Serial.printf("Wakeup was not caused by deep sleep: %d\n", wakeup_reason);
      break;
  }
}
