void setup(){
  for(int i=2; i<=11; i++){
    pinMode(i, OUTPUT);
  }
}
void loop(){
  for(int i=0; i<=4; i++){
    int ledLeft = 2 + i;
    int ledRight = 11 - i;
    digitalWrite(ledLeft, HIGH);
    digitalWrite(ledRight, HIGH);
    delay(100);
    digitalWrite(ledLeft, LOW);
    digitalWrite(ledRight, LOW);
    delay(100);
  }
  
  for(int i=0; i<=4; i++){
    int ledLeft = 6 - i;
    int ledRight = 7 + i;
    digitalWrite(ledLeft, HIGH);
    digitalWrite(ledRight, HIGH);
    delay(100);
    digitalWrite(ledLeft, LOW);
    digitalWrite(ledRight, LOW);
    delay(100);
  }
}
