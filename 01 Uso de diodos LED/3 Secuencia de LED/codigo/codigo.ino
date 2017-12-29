int led_verde=13;
int led_amarillo=12;
int led_rojo=11;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_verde,OUTPUT);
  pinMode(led_amarillo,OUTPUT);
  pinMode(led_rojo,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_verde,HIGH);
  delay(500);
  digitalWrite(led_verde,LOW);
  digitalWrite(led_amarillo,HIGH);
  delay(500);
  digitalWrite(led_amarillo,LOW);
  digitalWrite(led_rojo,HIGH);
  delay(500);
  digitalWrite(led_rojo,LOW);
}
