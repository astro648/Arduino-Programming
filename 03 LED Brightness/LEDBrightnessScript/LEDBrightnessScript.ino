#define LED_PIN 11

void setup() {
  pinMode(LED_PIN,OUTPUT);
  analogWrite(LED_PIN,118); // Change LED brightness by changing the number 0-255
}

void loop() {
  // put your main code here, to run repeatedly:

}
