/*Write an Arduino program that counts down from 30,
printing each integer along the way. Once the program reaches 0, 
it should print 0 and then stop counting. */

int i;
void setup(){
  Serial.begin(9600);
  for(i=30; i >= 0; i-- ){
  Serial.println(i);
    delay(100);
  }
  Serial.println("Done");
}

void loop(){}
