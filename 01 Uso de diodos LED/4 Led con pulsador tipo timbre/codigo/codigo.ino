const int led=13;
const int boton=7;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(boton,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(boton);
  if(val==HIGH){
    digitalWrite(led,HIGH);  
  }
  else{
    digitalWrite(led,LOW);  
  }
}
