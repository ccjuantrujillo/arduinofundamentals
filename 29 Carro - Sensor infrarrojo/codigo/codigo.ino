#include <Servo.h>

#include <IRremote.h>

int izquierda_motor_retroceder = 9;//IN1
int izquierda_motor_avanzar    = 5;//IN2
int derecha_motor_avanzar      = 6;//IN3
int derecha_motor_retroceder   = 10;//IN4
int RECV_PIN = 8;//Control remoto
IRrecv irrecv(RECV_PIN);
decode_results results;
int trig =A0;  //  Trigger p2.0
int echo = A1;  // Echo p2.1
Servo myServo;
int pos = 0;
int servo = 11;
/*Sirena policial*/
int duracion=250; //Duración del sonido
int fMin=2000; //Frecuencia más baja que queremos emitir
int fMax=4000; //Frecuencia más alta que queremos emitir
int i=0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(izquierda_motor_retroceder,OUTPUT);
  pinMode(izquierda_motor_avanzar,OUTPUT);  
  pinMode(derecha_motor_avanzar,OUTPUT);
  pinMode(derecha_motor_retroceder,OUTPUT);    
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  myServo.attach(servo);
}

void loop(){
  medir_distancia();
  if(irrecv.decode(&results)){
    
    Serial.println(results.value,HEX);
    irrecv.resume();
    delay(5);
    
    if(results.value==0x00FF02FD){
      avanzar(2000);
    }
    if(results.value==0x00FF9867){
      retroceder(2000);
    }    
    if(results.value==0x00FF906F){
      derecha(2000);
    } 
    if(results.value==0x00FFE01F){
      izquierda(2000);
    }     
    if(results.value==0x00FF22DD){
      giro_derecha(2000);
    }  
    if(results.value==0x00FFC23D){
      giro_izquierda(2000);
    }     
    if(results.value==0x00FFA857){
      detener(2000);
    }    
    if(results.value==0x00FFA25D){
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

void medir_distancia(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  float distancia = pulseIn(echo,HIGH);
  distancia = distancia/58;
  if(distancia<10){
    detener(1000);
    retroceder(500);
    mover_servo();
  }
  Serial.println(distancia);
}

void mover_servo(){
  int izquierda=0;
  int derecha =0;
  for(pos=0;pos<=180;pos+=1){
    myServo.write(pos);
    delay(15);
  }
  for(pos=180;pos>=90;pos-=1){
    myServo.write(pos);
    delay(15);
  }
}
