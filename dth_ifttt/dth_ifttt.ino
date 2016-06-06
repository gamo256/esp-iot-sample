#include "IFTTTESP8266.h"
#define EVENT  "<event name>"  // Put here your Maker Event Name
#define KEY  "<key>"  // Put here your IFTTT key
#define WIFISSID "<SSID>"
#define PASSWORD "<password>"

#include "DHT.h"
#define DHTPIN 4 // what digital pin we're connected to
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

IFTTT client(KEY);

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
    client.add(value1);
    client.add(value2);
    client.sendAll(EVENT);
}
