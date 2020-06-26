// #include libraries;
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "myNova";
const char* password = "12341234";

ESP8266WebServer server(80);
void handleRoot();
void handleNotFound();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  wifiConnect();
  server.begin();
  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

// Functions: 

//To connect wifi: 
void wifiConnect(){
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
    }
   Serial.print("\n");  
   Serial.print("Connected to: ");
   Serial.println(WiFi.localIP()); 
  }

  //HTML Servers
  void handleRoot(){
    server.send(200, "text/plain", "This is webServer");
    }

  void handleNotFound(){
    server.send(404, "text/plain", "404: Not found");
    }
