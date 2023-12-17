#include <Servo.h>
int motor_izquierdo_adelante = 9;//IN1
int motor_izquierdo_atras    = 8;//IN2
int motor_derecho_adelante   = 10;//IN3
int motor_derecho_atras      = 11;//IN4
int velocidad = 150;

void setup() {
  pinMode(motor_izquierdo_adelante,OUTPUT);
  pinMode(motor_izquierdo_atras,OUTPUT);
  pinMode(motor_derecho_adelante,OUTPUT);
  pinMode(motor_derecho_atras,OUTPUT);
}

void loop() {
  run(2000);//segundos
  stop(3000);
  back(2000);
  stop(3000);
  right(1000);
  left(1000);
  stop(3000);  
  spin_right(1000);
  spin_left(1000);
  stop(3000);
  for(int i=0;i<3;i++){
    run(1000);
    stop(500);
  }
  for(int i=0;i<3;i++){
    back(1000);
    stop(500);
  }  
  for(int i=0;i<3;i++){
    left(1000);
    spin_left(500);
  }  
  for(int i=0;i<3;i++){
    right(1000);
    spin_right(500);
  }    
}

void run(int tiempo){
    digitalWrite(motor_derecho_adelante,velocidad);
    digitalWrite(motor_derecho_atras,0);
    digitalWrite(motor_izquierdo_adelante,velocidad);
    digitalWrite(motor_izquierdo_atras,0);    
    delay(tiempo);
}

void stop(int tiempo){
    digitalWrite(motor_derecho_adelante,0);
    digitalWrite(motor_derecho_atras,0);
    digitalWrite(motor_izquierdo_adelante,0);
    digitalWrite(motor_izquierdo_atras,0);     
    delay(tiempo);
}

void back(int tiempo){
    digitalWrite(motor_derecho_adelante,0);
    digitalWrite(motor_derecho_atras,velocidad);
    digitalWrite(motor_izquierdo_adelante,0);
    digitalWrite(motor_izquierdo_atras,velocidad);    
    delay(tiempo);
}

void left(int tiempo){
    digitalWrite(motor_derecho_adelante,0);
    digitalWrite(motor_derecho_atras,0);
    digitalWrite(motor_izquierdo_adelante,velocidad);
    digitalWrite(motor_izquierdo_atras,0);    
    delay(tiempo);
}

void right(int tiempo){
    digitalWrite(motor_derecho_adelante,velocidad);
    digitalWrite(motor_derecho_atras,0);
    digitalWrite(motor_izquierdo_adelante,0);
    digitalWrite(motor_izquierdo_atras,0);    
    delay(tiempo);
}

void spin_right(int tiempo){
    digitalWrite(motor_derecho_adelante,velocidad);
    digitalWrite(motor_derecho_atras,0);
    digitalWrite(motor_izquierdo_adelante,0);
    digitalWrite(motor_izquierdo_atras,velocidad);    
    delay(tiempo);
}

void spin_left(int tiempo){
    digitalWrite(motor_derecho_adelante,0);
    digitalWrite(motor_derecho_atras,velocidad);
    digitalWrite(motor_izquierdo_adelante,velocidad);
    digitalWrite(motor_izquierdo_atras,0);    
    delay(tiempo);
}
