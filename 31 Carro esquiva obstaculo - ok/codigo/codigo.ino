#include <Servo.h>

Servo servos[13];

/***   Global variables   ***/
int motor_derecha=6;
int motor_derecha_retro=8;
int motor_izquierda=7;
int motor_izquierda_retro=9;
int distancia=0;
int servo=5;

/***   Function declaration   ***/
//bqBAT
long TP_init(int trigger_pin, int echo_pin);
long Distance(int trigger_pin, int echo_pin);
void avanzar ();
void detener ();
void retroceder ();
void izquierda ();
void derecha ();

void setup()
{








  pinMode( 12 , INPUT );

  pinMode( 13 , OUTPUT );

  Serial.begin(9600);

}


void loop()
{


    servos[servo].attach(servo);
    servos[servo].write(90);
    delay(500);
    distancia=Distance(13,12);
    if (distancia < 60) {
      detener();
      servos[servo].attach(servo);
      servos[servo].write(180);
      delay(500);
      int distancia_izq=Distance(13,12);
      Serial.println(distancia_izq);
      servos[servo].attach(servo);
      servos[servo].write(0);
      delay(500);
      int distancia_der=Distance(13,12);
      retroceder();
      delay(500);
      detener();
      delay(1000);
      if (distancia_izq < distancia_der) {
        derecha();
        delay(100);
       }else {
        izquierda();
        delay(100);
       }
     }else {
      avanzar();
     }

}

/***   Function definition   ***/
//bqBAT
long TP_init(int trigger_pin, int echo_pin)
{
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  long microseconds = pulseIn(echo_pin ,HIGH);
  return microseconds;
}
long Distance(int trigger_pin, int echo_pin)
{
  long microseconds = TP_init(trigger_pin, echo_pin);
  long distance;
  distance = microseconds/29/2;
  if (distance == 0){
    distance = 999;
  }
  return distance;
}
void avanzar () {
  pinMode(motor_derecha,OUTPUT);
  analogWrite(motor_derecha,255);
  pinMode(motor_derecha_retro,OUTPUT);
  analogWrite(motor_derecha_retro,0);
  pinMode(motor_izquierda,OUTPUT);
  analogWrite(motor_izquierda,255);
  pinMode(motor_izquierda_retro,OUTPUT);
  analogWrite(motor_izquierda_retro,0);
 }
void detener () {
  pinMode(motor_derecha,OUTPUT);
  analogWrite(motor_derecha,0);
  pinMode(motor_derecha_retro,OUTPUT);
  analogWrite(motor_derecha_retro,0);
  pinMode(motor_izquierda,OUTPUT);
  analogWrite(motor_izquierda,0);
  pinMode(motor_izquierda_retro,OUTPUT);
  analogWrite(motor_izquierda_retro,0);
 }
void retroceder () {
  pinMode(motor_derecha,OUTPUT);
  analogWrite(motor_derecha,0);
  pinMode(motor_derecha_retro,OUTPUT);
  analogWrite(motor_derecha_retro,255);
  pinMode(motor_izquierda,OUTPUT);
  analogWrite(motor_izquierda,0);
  pinMode(motor_izquierda_retro,OUTPUT);
  analogWrite(motor_izquierda_retro,255);
 }
void izquierda () {
  pinMode(motor_derecha,OUTPUT);
  analogWrite(motor_derecha,0);
  pinMode(motor_derecha_retro,OUTPUT);
  analogWrite(motor_derecha_retro,0);
  pinMode(motor_izquierda,OUTPUT);
  analogWrite(motor_izquierda,255);
  pinMode(motor_izquierda_retro,OUTPUT);
  analogWrite(motor_izquierda_retro,0);
 }
void derecha () {
  pinMode(motor_derecha,OUTPUT);
  analogWrite(motor_derecha,255);
  pinMode(motor_derecha_retro,OUTPUT);
  analogWrite(motor_derecha_retro,0);
  pinMode(motor_izquierda,OUTPUT);
  analogWrite(motor_izquierda,0);
  pinMode(motor_izquierda_retro,OUTPUT);
  analogWrite(motor_izquierda_retro,0);
 }
