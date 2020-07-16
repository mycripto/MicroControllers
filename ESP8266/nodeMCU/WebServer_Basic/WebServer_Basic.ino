//https://gist.github.com/bbx10/5a2885a700f30af75fc5
//Include Libraries;

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);
#include <WiFiClient.h>

#define LEDPIN LED_BUILTIN

//HTML file
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
"</html>";


void setup() {
  Serial.begin(115200);
  Serial.println("");
  startWifi();
  pinMode(LEDPIN, OUTPUT);
  writeLED(false);

  server.on("/", handleRoot );
  server.on("/ledon",handleLEDon );
  server.on("/ledoff", handleLEDoff );
  server.onNotFound(handleNotFound);
  server.begin();
}


void loop() {
  server.handleClient();
  }

//functions:

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


  //Handles
  void handleRoot(){
    server.send(200, "text/html", INDEX_HTML);
    }

  void handleLEDon(){
    writeLED(true);  
    }  
  void handleLEDoff(){
    writeLED(false);    
    }
  void handleNotFound(){
    server.send(404, "text/plain", "Not found");
    }
    
