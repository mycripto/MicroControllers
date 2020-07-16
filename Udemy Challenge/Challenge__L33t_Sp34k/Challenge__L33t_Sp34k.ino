
String input;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(200); // set time out to 200ms
  delay(10);
  Serial.print("\n");
  //##################################
  Serial.println("<Please write something in Serial>");
  Serial.print("\n");

}

void loop () {
  while (Serial.available()) {
    delay(2);
    char text = Serial.read();
    input += text;
  }
  if (input.length() > 0) {
    Serial.print("input text: ");
    Serial.print(input);
    Serial.print("\n");
    Serial.print("L33t Sp34k: ");
    converter();
    input = "";
    Serial.print("\n");

  }
}

String converter() { // Converter vowels to int.
  //Serial.print(input.length());
  for (char i = 0; i < input.length(); i++) {
    if ( input[i] == 'E' || input[i] == 'e') {
      input[i] =  '3';
    }
    if ( input[i] == 'A' || input[i] == 'a') {
      input[i] =  '4';
    }
    if ( input[i] == 'I' || input[i] == 'i') {
      input[i] =  '1';
    }
  }
  Serial.print(input);
}
