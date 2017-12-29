const int led=A4;
const int pot=A1;
int brillo;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  brillo=analogRead(pot)/4;
  analogWrite(led,brillo);
}
