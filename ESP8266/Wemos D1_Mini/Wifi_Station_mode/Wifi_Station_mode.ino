//Station mode
#include <ESP8266WiFi.h> //Include the WiFi library

const char* ssid = "myNova"; // SSID name
const char* password = "12341234"; //Wifi password

void setup(){
  Serial.begin(115200); //Start serial
  delay(10);
  Serial.println('\n');
  WiFi.begin(ssid, password); //Wifi start with ssid and password
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.print("...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(++i);
    Serial.print(' ');
  }
  Serial.print('\n');
  Serial.print("Connected to "); Serial.println(ssid);
  Serial.print("IP address: \t");
  Serial.println(WiFi.localIP());
  
  }
void loop(){}

/*
 #Main code to connct WiFi. 
 #include <ESP8266WiFi.h> //Include the WiFi library
  const char* ssid = "myNova"; // SSID name
  const char* password = "12341234"; //Wifi password
  WiFi.begin(ssid, password); //Wifi start with ssid and password

*/
