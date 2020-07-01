#define sensorPin A0



void setup(){
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  }
  
void loop(){
  float sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(2000);
  }
  
