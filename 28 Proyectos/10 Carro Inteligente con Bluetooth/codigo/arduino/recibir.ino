#include <SoftwareSerial.h>

#define rxPin 5//rx de Arcuino
#define txPin 6//tx de arduino
SoftwareSerial mySerial(rxPin, txPin);
char myChar ;

void setup()  
{
  Serial.begin(9600);
  mySerial.begin(38400);
}

void loop()
{
  if (mySerial.available())
  {
    char dato=mySerial.read();
    Serial.print("Dato recibido: ");
    Serial.println(dato);
  }
  delay(500);
}
