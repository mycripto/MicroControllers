#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(9600);
  startWifi();
}

void loop() {}

void startWifi() {
//To call this fucntion: startWifi();
//Library: #include <ESP8266WiFi.h>

  const char* ssid = "myNova";
  const char* pass = "12341234";

  WiFi.begin(ssid, pass);
  Serial.println( " " );
  Serial.print("Wifi is connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" ");
  Serial.print("Wifi Connected, IP address: ");
  Serial.print(WiFi.localIP());
} //end of startWifi function//
