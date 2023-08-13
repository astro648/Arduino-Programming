void setup() {
  //pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //digitalWrite(13,HIGH);
  // delay(1000);
  // digitalWrite(13,LOW);
  // delay(1000);

  if(Serial.available() == 1){
    char value = Serial.read();
    Serial.print(value);
  }
}
