#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti wifiMulti; // Create an instance of the ESP8266WiFiMulti class,
#include <ESP8266mDNS.h>

void setup() {
  Serial.begin(9600);
  Serial.print("\n");
  delay(10);
  startMultiWifi();

}

void loop () {

}

void startMultiWifi() {
  /*
    #### //Libraries to include #####
    #include <ESP8266WiFi.h>
    #include <ESP8266WiFiMulti.h>
    ESP8266WiFiMulti wifiMulti; // Create an instance of the ESP8266WiFiMulti class,
    #include <ESP8266mDNS.h>
  */

  wifiMulti.addAP("myNova", "12341234");
  wifiMulti.addAP("HomeWifi 2g", "familynet203");
  Serial.println("Connecting ...");
  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());              // Tell us what network we're connected to
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());           // Send the IP address of the ESP8266 to the computer

  if (!MDNS.begin("esp8266")) {             // Start the mDNS responder for esp8266.local
    Serial.println("Error setting up MDNS responder!");
  }
  Serial.println("mDNS responder started");

}
