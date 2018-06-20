int pinTrigger = A4;//IN5 TRIGGER
int pinEcho = A5;//IN6 ECHO
int izquierda_motor_b = 9;//IN1
int izquierda_motor_a = 5;//IN2
int derecha_motor_a = 6;  //IN3
int derecha_motor_b = 10; //IN4
float distancia = 0;
int numero;

void setup(){
  Serial.begin(9600);
  pinMode(pinTrigger,OUTPUT);
  pinMode(pinEcho,INPUT);
  pinMode(izquierda_motor_a,OUTPUT);
  pinMode(izquierda_motor_b,OUTPUT);
  pinMode(derecha_motor_a,OUTPUT);
  pinMode(derecha_motor_b,OUTPUT);
}

void loop(){
  avanzar();
  medir_distancia();
  Serial.println(distancia);
  if(distancia<20){
    detener();
    delay(1000);
    retroceder();
    delay(1000);
    numero = (int)random(0,2);
    if(numero==1){
      derecha();
      delay(500);
    }
    else if(numero==0){
      izquierda();
      delay(500);
    }
    Serial.println(numero);
  }
}

void medir_distancia(){
  digitalWrite(pinTrigger,LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrigger,HIGH);  
  delayMicroseconds(10);
  digitalWrite(pinTrigger,LOW); 
  distancia = pulseIn(pinEcho,HIGH)*0.017;
}

void avanzar(){
  analogWrite(izquierda_motor_a,0);
  analogWrite(izquierda_motor_b,255);
  analogWrite(derecha_motor_a,0);
  analogWrite(derecha_motor_b,255);
}

void detener(){
  analogWrite(izquierda_motor_a,0);
  analogWrite(izquierda_motor_b,0);
  analogWrite(derecha_motor_a,0);
  analogWrite(derecha_motor_b,0);
}

void retroceder(){
  analogWrite(izquierda_motor_a,255);
  analogWrite(izquierda_motor_b,0);
  analogWrite(derecha_motor_a,255);
  analogWrite(derecha_motor_b,0);
}

void derecha(){
  analogWrite(izquierda_motor_a,0);
  analogWrite(izquierda_motor_b,0);
  analogWrite(derecha_motor_a,255);
  analogWrite(derecha_motor_b,0);
}

void izquierda(){
  analogWrite(izquierda_motor_a,255);
  analogWrite(izquierda_motor_b,0);
  analogWrite(derecha_motor_a,0);
  analogWrite(derecha_motor_b,0);
}
