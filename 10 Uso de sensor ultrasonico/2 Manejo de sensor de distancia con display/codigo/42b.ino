#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);
long distancia;
long tiempo;

void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
}

void loop() {
  digitalWrite(3,LOW);
  delayMicroseconds(5);
  digitalWrite(3,HIGH);
  delayMicroseconds(10);
  tiempo = pulseIn(4,HIGH);
  distancia = int(0.017*tiempo);
  Serial.println("Distancia...");
  Serial.println(distancia);
  Serial.println(" cm");

  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.print(distancia);
  
  
  delay(1000);
}

