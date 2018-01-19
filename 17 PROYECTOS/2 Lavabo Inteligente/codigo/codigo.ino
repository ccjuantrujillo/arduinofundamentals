long distancia;
long tiempo;
int pinTrigger = 3;
int pinEco     = 4;
int pinCano    = 5; 
int pinAlarma  = 6;
int estado = 0;
int estado_old = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinTrigger,OUTPUT);
  pinMode(pinEco,INPUT);
  pinMode(pinCano,OUTPUT);
  pinMode(pinAlarma,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinTrigger,LOW);
  delayMicroseconds(5);
  digitalWrite(pinTrigger,HIGH);
  delayMicroseconds(10);
  tiempo = pulseIn(pinEco,HIGH);
  distancia = int(0.017*tiempo);
  Serial.println(distancia);

  //Si acercamos las manos se abre el año
  if(distancia<40){
    digitalWrite(pinCano,HIGH);
    estado = 1;
  }
  else{
    estado = 0;
    if(estado_old==1 && estado==0) delay(3000);
    digitalWrite(pinCano,LOW);
  }
  estado_old = estado;
  //Si la distancia sobrepasa los 60cm se enciende la alarma y queda encendida
  if(distancia>=80){
    digitalWrite(pinAlarma,HIGH);
  }
}
