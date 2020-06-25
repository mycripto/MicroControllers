#include <ESP8266WiFi.h>
const char* ssid = "myNova";
const char* password = "12341234";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  //WiFi.status() != WL_CONNECTED;
  //delay(2000);
  //Serial.print('\n');
 

}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println(WiFi.localIP());
   delay(2000);

}
