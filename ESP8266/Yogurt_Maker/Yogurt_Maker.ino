#include <SimpleTimer.h>           // Allows us to call functions without putting them in loop()

#define BLYNK_PRINT Serial         // Comment this out to disable prints and save space
#include <BlynkSimpleEsp8266.h> 

#include <OneWire.h>
#include <DallasTemperature.h> 
#define ONE_WIRE_BUS 0          // Your ESP8266 pin (ESP8266 GPIO 2 = WeMos D1 Mini pin D4)
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//char auth[] = "EWTbVkCt0U4SBDEYNjxykPCTfLt78Fkg"; // Home LocalServer
char auth[] = "TJr7Yn9Mm3607dIHSmMlG5cKZzC-XuhL"; // Home WiFi

char ssid[] = "HomeWifi 2g";
char pass[] = "familynet203";

SimpleTimer timer;

int roomTemperature;            // Room temperature in F

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,0,133), 8080);

  while (Blynk.connect() == false) {
    // Wait until connected
  }

  sensors.begin();                        // Starts the DS18B20 sensor(s).
  sensors.setResolution(10);              // More on resolution: http://www.homautomation.org/2015/11/17/ds18b20-how-to-change-resolution-9101112-bits/

  timer.setInterval(1000L, sendTemps);    // Temperature sensor read interval. 2000 (ms) = 2 seconds.
  digitalWrite(2, HIGH);
}

// Notice how there is very little in the loop()? Blynk works best that way.
void loop()
{
  Blynk.run();
  timer.run();
}

// Notice how there are no delays in the function below? Blynk works best that way.
void sendTemps()
{
  sensors.requestTemperatures();                  // Polls the sensors.
  roomTemperature = sensors.getTempCByIndex(0);   // Stores temperature. Change to getTempCByIndex(0) for celcius.
  Blynk.virtualWrite(1, roomTemperature);         // Send temperature to Blynk app virtual pin 1.
}
