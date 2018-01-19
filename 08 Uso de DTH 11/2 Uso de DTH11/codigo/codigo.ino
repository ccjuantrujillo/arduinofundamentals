#include "DHT.h" 
DHT dht(2, DHT11 );

void setup() {
Serial.begin(9600); 
dht.begin(); 
}

void loop() {
float h = dht.readHumidity(); 
float t = dht.readTemperature(); 
Serial.println("Humedad: "); 
Serial.println(h);
Serial.println("Temperatura: ");
Serial.println(t);
delay(2000); 
}

