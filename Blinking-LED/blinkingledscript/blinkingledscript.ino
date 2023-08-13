// + connected to digital pin 12
void setup() {
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  delay(3000);
}

void loop() {
  digitalWrite(12,LOW);
  delay(500);
  digitalWrite(12,HIGH);
  delay(500);
}
