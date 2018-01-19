#include <Servo.h>
Servo myServo;
Servo myServo2;
int pos=0;
int pos2=0;

void setup() {
  myServo.attach(8);//Servo horizontal
  myServo2.attach(7);//Servo vertical
}

void loop() {
  /*Controlamos el servo horizontal*/
  for(pos=60;pos<=180;pos+=1){
    myServo.write(pos);
    delay(30);
  }
  for(pos=180;pos>=60;pos-=1){
    myServo.write(pos);
    delay(30);
  }
  /*Controlamos el servo vertical*/
  for(pos2=60;pos2<=140;pos2+=1){
    myServo2.write(pos2);
    delay(30);
  }  
  for(pos2=140;pos2>=600;pos2-=1){
    myServo2.write(pos2);
    delay(30);
  }  
}
