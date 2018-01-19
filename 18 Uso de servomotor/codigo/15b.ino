#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <Servo.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double sensor;
Servo servo_8;

void setup(){
    Serial.begin(115200);
    pinMode(A0+0,INPUT);
    pinMode(6,OUTPUT);
    servo_8.attach(8); // init pin
}

void loop(){
    sensor = analogRead(A0+0);
    Serial.println(sensor);
    if((sensor) < (600)){
        digitalWrite(6,1);
        servo_8.write(0); // write to servo
    }else{
        digitalWrite(6,0);
        servo_8.write(90); // write to servo
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}
