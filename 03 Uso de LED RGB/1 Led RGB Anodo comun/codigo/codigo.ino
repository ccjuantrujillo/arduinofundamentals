int rojo = 9;
int verde = 10;
int azul = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(rojo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(azul,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  establecerColor(random(127,255),random(127,255),random(127,255));
  delay(1000);
}

void establecerColor(int R,int G,int B){
  analogWrite(rojo,255-R);
  analogWrite(verde,255-G);
  analogWrite(azul,255-B);
}

