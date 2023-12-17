#include <Servo.h>
#include <IRremote.h>
int izquierda_motor_retroceder = 9;//IN1
int izquierda_motor_avanzar    = 5;//IN2
int derecha_motor_avanzar      = 6;//IN3
int derecha_motor_retroceder   = 10;//IN4
int RECV_PIN = 8;//Control remoto
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(izquierda_motor_retroceder,OUTPUT);
  pinMode(izquierda_motor_avanzar,OUTPUT);  
  pinMode(derecha_motor_avanzar,OUTPUT);
  pinMode(derecha_motor_retroceder,OUTPUT);    
}
void loop(){
  if(irrecv.decode(&results)){    
    Serial.println(results.value,HEX);
    irrecv.resume();
    delay(5);    
    if(results.value==0x00FF18E7){//Tecla 2
      avanzar(2000);
    }
    if(results.value==0x00FF4AB5){//Tecla 8
      retroceder(2000);
    }    
    if(results.value==0x00FF5AA5){//Tecla 6
      derecha(2000);
    } 
    if(results.value==0x00FF10EF){//Tecla 4
      izquierda(2000);
    }     
    if(results.value==0x00FF02FD){//Tecla >>
      giro_derecha(2000);
    }  
    if(results.value==0x00FF22DD){//Tecla <<
      giro_izquierda(2000);
    }     
    if(results.value==0x00FF38C7){//Tecla 5
      detener(2000);
    }    
    if(results.value==0x00FF906F){//Tecla EQ
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
  }
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
