const int pin = 9;
int ldr = A0;

void setup() {
  Serial.begin(9600);
  pinMode(pin,OUTPUT);
}

void loop() {
  int valor=analogRead(ldr);
  Serial.println(valor);
  digitalWrite(pin,HIGH);
  delay(5000);
  digitalWrite(pin,LOW);
  delay(2000);
}
