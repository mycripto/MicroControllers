/*
Summary:
1. include lybraries: {Wifi, wifiClient, WebServer, mDNS}
2. define: {Wifi credentials, HTTP protocols, WebServer port}
3. void setup: [{start: Serial, Wifi, server}
                        { server: .on, .onNotFound,}
                        {pinMode}

4. void loop: server.handleClient
*/
//#########################################################//

// 1. #include libraries;
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

//2. define: {Wifi credentials, HTTP protocols}
const char* ssid = "myNova";
const char* password = "12341234";

//HTTP protocols
void handleRoot();
void handleNotFound();
void handleLED();

//WebServer port
ESP8266WebServer server(80);


void setup() {
  // [{start: Serial, Wifi, server}
  Serial.begin(9600);
  WiFi.begin(ssid, password); 
  server.begin();
  wifiConnect();
  MDNS.begin("esp8266");
  
  //server: .on, .onNotFound,
  server.on("/", HTTP_GET, handleRoot);
  server.on("/LED", HTTP_POST, handleLED);
  server.onNotFound(handleNotFound);

  //{pinMode}
   pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // server.handleClient
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
    server.send(200, "text/html", "<form action=\"/LED\" method=\"POST\"><input type=\"submit\" value=\"Toggle LED\"></form>");
    }

  void handleNotFound(){
    server.send(404, "text/plain", "404: Not found");
    }

    void handleLED(){
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      server.sendHeader("Location","/");
      server.send(303);
      }
