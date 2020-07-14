#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//start server port
WiFiServer server(80);

//Prepare HTML
String prepareHtmlPage(){
  String htmlPage =
  String("HTTP/1.1 200 OK\r\n")+
  "Content-Type: text/html\r\n"+
  "Connection: Close\r\n"+
  "Refresh: 5\r\n"+
  "\r\n"+
  "<!DOCTYPE HTML>"+
  "<html>"+
  "Analog input: " + String(analogRead(A0)) +
  "</html>"+
  "\r\n" 
  return htmlPage;
  }

//#############################################################################
void setup() {
  Serial.begin(9600);
  startWifi();
  server.begin();
}

//#############################################################################
void loop() {}

//#############################################################################
//Functions

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
