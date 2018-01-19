int sensorPin=A2;
const int ledPin=9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  int value = analogRead(sensorPin);
  float milivolts = (value/1023)*5000;
  float celsius = milivolts/10;
  Serial.print(celsius);
  Serial.println(" C");
  delay(1000);

  digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(ledPin,LOW);
  delay(1000);
}
