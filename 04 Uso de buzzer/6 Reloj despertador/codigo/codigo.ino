int buzzer = 13;

void setup() {
  pinMode(buzzer,OUTPUT);
  beep(50);
  beep(50);
  beep(50);
  delay(1000);
}

void loop() {
  beep(200);
}

void beep(unsigned char pausa){
  analogWrite(buzzer,20);
  delay(pausa);
  analogWrite(buzzer,0);
  delay(pausa);
}
