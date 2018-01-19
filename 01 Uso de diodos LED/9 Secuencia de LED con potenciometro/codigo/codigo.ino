int pot = A1;
int valor = 0;
int led1 = 11;
int led2 = 12;
int led3 = 13;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(pot,INPUT);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor = analogRead(pot)/2;
  Serial.println(valor,DEC);

  /*Secuencia de leds*/
  digitalWrite(led1,HIGH);
  delay(valor);
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  delay(valor);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
  delay(valor);
  digitalWrite(led3,LOW);
}
