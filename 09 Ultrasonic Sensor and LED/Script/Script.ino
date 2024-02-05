const int trigPin = 4;
const int echoPin = 3;
#define LED_RED 12
#define LED_YELLOW 11
#define LED_GREEN 10

float d,t;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LED_RED, OUTPUT);
pinMode(LED_YELLOW, OUTPUT);
pinMode(LED_GREEN, OUTPUT);
Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  t = pulseIn(echoPin, HIGH);
  d= 0.034*t/2;

  Serial.print("Distance: ");
  Serial.println(d);
  Serial.println();
  delay(200);

  if(d>=20){
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, HIGH);
  }
  else if(d>=10 && d<=20){
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, HIGH);
  }
  else if(d<10){
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, HIGH);
  }
}