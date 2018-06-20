int izquierda_motor_avanzar    = 6;//IN1
int izquierda_motor_retroceder = 7;//IN2
int derecha_motor_avanzar      = 8;//IN3
int derecha_motor_retroceder   = 9;//IN4

void setup(){
  pinMode(izquierda_motor_retroceder,OUTPUT);
  pinMode(izquierda_motor_avanzar,OUTPUT);  
  pinMode(derecha_motor_avanzar,OUTPUT);
  pinMode(derecha_motor_retroceder,OUTPUT);    
}

void loop(){
  delay(500);
  avanzar(2000);
  detener(1000);
  retroceder(2000);
  detener(1000);  
  derecha(2000);
  detener(1000);  
  izquierda(2000);
  detener(1000);  
  giro_derecha(2000);
  detener(1000);  
  giro_izquierda(2000);
  detener(1000);  
}

void detener(int tiempo){
  analogWrite(izquierda_motor_avanzar,0);
  analogWrite(izquierda_motor_retroceder,0);
  analogWrite(derecha_motor_avanzar,0);
  analogWrite(derecha_motor_retroceder,0);
  delay(tiempo);
}

void avanzar(int tiempo){
  analogWrite(izquierda_motor_avanzar,255);
  analogWrite(izquierda_motor_retroceder,0);
  analogWrite(derecha_motor_avanzar,255);
  analogWrite(derecha_motor_retroceder,0);
  delay(tiempo);
}

void retroceder(int tiempo){
  analogWrite(izquierda_motor_avanzar,0);
  analogWrite(izquierda_motor_retroceder,255);
  analogWrite(derecha_motor_avanzar,0);
  analogWrite(derecha_motor_retroceder,255);
  delay(tiempo);
}

void derecha(int tiempo){
  analogWrite(izquierda_motor_avanzar,0);
  analogWrite(izquierda_motor_retroceder,0);
  analogWrite(derecha_motor_avanzar,255);
  analogWrite(derecha_motor_retroceder,0);
  delay(tiempo);
}

void izquierda(int tiempo){
  analogWrite(izquierda_motor_avanzar,255);
  analogWrite(izquierda_motor_retroceder,0);
  analogWrite(derecha_motor_avanzar,0);
  analogWrite(derecha_motor_retroceder,0);
  delay(tiempo);
}

void giro_derecha(int tiempo){
  analogWrite(izquierda_motor_avanzar,0);
  analogWrite(izquierda_motor_retroceder,255);
  analogWrite(derecha_motor_avanzar,255);
  analogWrite(derecha_motor_retroceder,0);
  delay(tiempo);
}

void giro_izquierda(int tiempo){
  analogWrite(izquierda_motor_avanzar,255);
  analogWrite(izquierda_motor_retroceder,0);
  analogWrite(derecha_motor_avanzar,0);
  analogWrite(derecha_motor_retroceder,255);
  delay(tiempo);
}
