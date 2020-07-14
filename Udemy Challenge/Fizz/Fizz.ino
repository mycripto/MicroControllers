int a = 1;
#define ledPin 13

void setup(){
  Serial.begin(9600);
  
  
  
}
void loop (){
  
  if(a%3 == 0){
    Serial.println( "Fizz" );   
  
  } else {
    Serial.println(a);
  }
   a++;
  delay(1000);
}
