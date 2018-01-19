#include <LiquidCrystal.h>
#include <DHT11.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//Declaramos los pines de nuestra pantalla

int pin = 8;//Pin donde va conectado el sensor de temperatura
DHT11 dht11(pin);

void setup() {
  Serial.begin(9600);

  /*Inicializamos el LCD*/
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("S.E.N.A.T.I.");
  delay(2000); 
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Ardunino &");
  delay (1000);
  lcd.setCursor(8, 1);
  lcd.print("Domotica");
  delay (2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ESTACION");
  delay (1000);
  lcd.setCursor(0, 1);
  lcd.print("METEOROLOGICA");
  delay (2000);
  lcd.clear();
}

void loop() {
  delay(2000);  
  int err;
   float temp,hum;
  if((err=dht11.read(hum, temp)) == 0){
    /*Visualizamos en monitor serial*/
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" *C");
    //Visualizamos en LCD
    lcd.setCursor(0, 0);
    lcd.print("TEMPERATURA");
    lcd.setCursor(12, 0);
    lcd.print(temp);
    lcd.setCursor(14, 0);
    lcd.print(" C");
    delay(100);
  }
  else{
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();   
  }
}
