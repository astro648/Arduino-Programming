#define BUTTON_PIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BUTTON_PIN) == HIGH){
    Serial.println("Button is pressed!");
  } else {
    Serial.println("Button is not pressed.");
  }
  delay(100); 
}
