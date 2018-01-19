int pinzumbador = 13;
int frecuencia = 440;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(pinzumbador,frecuencia);
  delay(2000);
  noTone(pinzumbador);
  delay(1000);
}
