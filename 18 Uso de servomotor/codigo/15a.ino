#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double sensor;

void setup(){
    Serial.begin(9600);
    pinMode(A0+0,INPUT);
    pinMode(6,OUTPUT);
}

void loop(){
    sensor = analogRead(A0+0);
    Serial.println(sensor);
    if((sensor) < (400)){
        digitalWrite(6,1);
    }else{
        digitalWrite(6,0);
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}
