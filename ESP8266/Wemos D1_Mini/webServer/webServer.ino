#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);


void html();

void handleRoot();
void handleNotFound();

void setup() {
  Serial.begin(9600);
  delay(10);
  wifiMulti.addAP("HomeWifi 2g", "familynet203");

  int i = 9;
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(250);
  }
  Serial.println(WiFi.localIP());

  MDNS.begin("ESP8266");
  server.begin();

  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
}


void loop() {
  server.handleClient();

}

void handleRoot() {
  server.send(200, "text/html", html(INDEX_HTML));
}

void handleNotFound() {
  server.send(404, "text/plain", "404: Not Found");
}

void html(){
  // HTML
const char INDEX_HTML[] =
  "<!DOCTYPE HTML>"
  "<html>"
  "<head>"
  "<meta name = \"viewport\" content = \"width = device-width, initial-scale = 1.0, maximum-scale = 1.0, user-scalable=0\">"
  "<title>ESP8266 Web Form Demo</title>"
  "<style>"
  "\"body { background-color: #808080; font-family: Arial, Helvetica, Sans-Serif; Color: #000000; }\""
  "</style>"
  "</head>"
  "<body>"
  "<h1>ESP8266 Web Form Demo</h1>"
  "<FORM action=\"/\" method=\"post\">"
  "<P>"
  "LED<br>"
  "<INPUT type=\"radio\" name=\"LED\" value=\"1\">On<BR>"
  "<INPUT type=\"radio\" name=\"LED\" value=\"0\">Off<BR>"
  "<INPUT type=\"submit\" value=\"Send\"> <INPUT type=\"reset\">"
  "</P>"
  "</FORM>"
  "</body>"
  "</html>";}
