//ledPin a number between 4 to 13 in Serial ledPin to toggle LED;

int ledPin;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(200);
  delay(10);
  Serial.print("\n");
  //pinMode(13, OUTPUT);
  Serial.println(" Please Enter LED number between 4 to 13 ");
  Serial.print("\n");
}

void loop () {
  //ledPin = "";
  readSerial ();
}

//######################---FUNCTIONS---#################//

char readSerial () {
  while (Serial.available()) {
    String text = Serial.readString(); //read ledPin as String;
    //Serial.print("Your last input: LED number ");
    ledPin = text.toInt(); //convert to integer;
    
    if(ledPin >= 4 && ledPin <=13){    
    //pinMode(ledPin, OUTPUT);
    //digitalWrite(ledPin, !digitalRead(ledPin));
      ledToggle();
      Serial.print("Your last input: LED number ");
      Serial.println(ledPin);
    } else {
      Serial.println("Invalid LED number");
    }
  }
}

void ledToggle(){
  pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, !digitalRead(ledPin));
}
