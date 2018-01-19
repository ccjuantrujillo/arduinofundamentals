int led=3;
int pot=A1;
int brillo;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  /*Los pines analogicos se declaran de manera automatica como entrada*/
}

void loop() {
  // put your main code here, to run repeatedly:
  brillo=analogRead(pot)/4;
  analogWrite(led,brillo);
}
