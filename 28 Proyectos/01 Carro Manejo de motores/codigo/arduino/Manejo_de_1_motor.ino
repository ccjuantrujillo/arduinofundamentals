int izquierda_motor_avanzar    = 13;//IN1
int izquierda_motor_retroceder = 12;//IN2
int derecha_motor_avanzar    = 11;//IN3
int derecha_motor_retroceder = 10;//IN4
int velocidad = 255;

void setup(){
  pinMode(izquierda_motor_avanzar,OUTPUT);    
  pinMode(izquierda_motor_retroceder,OUTPUT);
  pinMode(derecha_motor_avanzar,OUTPUT);    
  pinMode(derecha_motor_retroceder,OUTPUT);
}
void loop(){
  avanzar();
  delay(1000);
  detener();
  delay(1000);
  retroceder();
  delay(1000);
  detener();
  delay(1000);
  derecha();
  delay(1000);
  detener();  
  delay(1000);
  izquierda();
  delay(1000);
  detener();  
  delay(1000);
  giro_derecha();
  delay(1000);
  detener();  
  delay(1000);
  giro_izquierda();
  delay(1000);
  detener();  
  delay(1000); 
}
void detener(){
  analogWrite(izquierda_motor_avanzar,0);
  analogWrite(izquierda_motor_retroceder,0);  
  analogWrite(derecha_motor_avanzar,0);
  analogWrite(derecha_motor_retroceder,0);
}
void avanzar(){
  analogWrite(izquierda_motor_avanzar,velocidad);
  analogWrite(izquierda_motor_retroceder,0);    
  analogWrite(derecha_motor_avanzar,velocidad);
  analogWrite(derecha_motor_retroceder,0);
}
void retroceder(){
  analogWrite(izquierda_motor_avanzar,0);
  analogWrite(izquierda_motor_retroceder,velocidad);    
  analogWrite(derecha_motor_avanzar,0);
  analogWrite(derecha_motor_retroceder,velocidad);
}
void derecha(){
  analogWrite(izquierda_motor_avanzar,velocidad);
  analogWrite(izquierda_motor_retroceder,0);     
  analogWrite(derecha_motor_avanzar,0);
  analogWrite(derecha_motor_retroceder,0);
}
void izquierda(){
  analogWrite(izquierda_motor_avanzar,0);
  analogWrite(izquierda_motor_retroceder,0);     
  analogWrite(derecha_motor_avanzar,velocidad);
  analogWrite(derecha_motor_retroceder,0);
}
void giro_derecha(){
  analogWrite(izquierda_motor_avanzar,velocidad);
  analogWrite(izquierda_motor_retroceder,0);     
  analogWrite(derecha_motor_avanzar,0);
  analogWrite(derecha_motor_retroceder,velocidad);
}
void giro_izquierda(){
  analogWrite(izquierda_motor_avanzar,0);
  analogWrite(izquierda_motor_retroceder,velocidad);     
  analogWrite(derecha_motor_avanzar,velocidad);
  analogWrite(derecha_motor_retroceder,0);
}
