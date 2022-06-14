void setup() {
  pinMode(D4,OUTPUT);   //Configuro D4 como salida
}

void loop() {
  digitalWrite(D4, HIGH);
  delay(1000);
  digitalWrite(D4, LOW);
  delay(1000);
}
