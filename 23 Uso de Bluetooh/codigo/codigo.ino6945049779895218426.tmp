#include <SoftwareSerial.h>

#define rxPin 9
#define txPin 11

SoftwareSerial mySerial(rxPin, txPin);
char myChar ;

void setup() {
  Serial.begin(9600);   
  Serial.println("AT");

  mySerial.begin(38400);
  mySerial.println("AT");
  pinMode(13,OUTPUT);
}

void loop() {
  while (mySerial.available()) {
    myChar = mySerial.read();
    //Serial.print(myChar);
  }

  while (Serial.available()) {
    myChar = Serial.read();
    //Serial.print(myChar); 
    mySerial.print(myChar);
  }
Serial.print(myChar);
  if(myChar=='E'){
     digitalWrite(13, HIGH);
  }

  if(myChar=='A'){
     digitalWrite(13, LOW);
  }  
}
