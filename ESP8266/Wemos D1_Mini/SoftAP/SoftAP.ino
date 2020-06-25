#include <ESP8266WiFi.h>
const char* ssid = "WifiName";
const char* password = "passw0rd"; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(WiFi.softAPIP());
  delay(2000);

}
