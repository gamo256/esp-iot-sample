#include "UbidotsMicroESP8266.h"

#define SSID "<SSID>"
#define PASS "<password>"

#define TOKEN "<Token>"     // Put here your Ubidots TOKEN
#define ID "<variable ID>"  // Put here your Ubidots variable ID
#define ID2 <variable ID>" 

#include "DHT.h"
#define DHTPIN 4 // what digital pin we're connected to
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

Ubidots client(TOKEN);

void setup() {
    Serial.begin(115200);
    delay(10);
    client.wifiConnection(SSID, PASS);
  
    dht.begin();
}


void loop() {

  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read humidity
  float h = dht.readHumidity();

  client.add(ID,t);
  client.add(ID2,h);

  client.sendAll();
}
