#include "dweetESP8266.h"
#define THIG_NAME  "dweet_esp_dht"  // Put here your thing name
#define WIFISSID "<SSID>"
#define PASSWORD "<password>"

#include "DHT.h"
#define DHTPIN 4 // what digital pin we're connected to
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

dweet client;

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup(){
    Serial.begin(115200);
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);

    dht.begin();
}
void loop(){

    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read humidity
    float h = dht.readHumidity();
  
    String value1 = String(t);
    String value2 = String(h);
    client.add("temperature", value1);
    client.add("humidity", value2);
    client.sendAll(THIG_NAME);
}
