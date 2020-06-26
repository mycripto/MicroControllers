#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);

void handleRoot();
void handleNotFound();

void setup(){
  Serial.begin(115200);
  delay(10);
  wifiMulti.addAP("myNova", "12341234");

  int i = 9;
  while (wifiMulti.run() != WL_CONNECTED){
    delay(250);
  }
  Serial.println(WiFi.localIP());

  MDNS.begin("ESP8266");
  server.begin();

  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  }

  
void loop(){
  server.handleClient();
  
  }

  void handleRoot(){
    server.send(200, "text/plain", "Hello World");
    }

  void handleNotFound(){
    server.send(404, "text/plain", "404: Not Found");
    }
