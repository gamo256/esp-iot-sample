#include "dweetESP8266.h"
#define THIG_NAME  "esp-led-onoff"  // Put here your thing name
#define WIFISSID "ssid"
#define PASSWORD "password"

// LED pin
const int led_pin = 5;

dweet client;

void setup() {
    // Set lamp pin to output
    pinMode(led_pin, OUTPUT);
    
    Serial.begin(115200);
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
}
void loop() {
      String value = client.getDweet(THIG_NAME, "action");
      if (value == "on") {digitalWrite(led_pin, HIGH);}
      if (value == "off") {digitalWrite(led_pin, LOW);}
}

