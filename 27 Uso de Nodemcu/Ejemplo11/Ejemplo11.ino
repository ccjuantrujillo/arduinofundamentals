#include <DHT.h>

int sensor=5;
int temp;
int hum;

DHT dht(sensor,DHT11);//llamaremos al objeto : dht indicaremos el pin conectado(2) y el modelo(dht11);


void setup() {
Serial.begin(9600);
dht.begin();//indicamos al objeto dht la relacion con el monitor serial
}

void loop() {
temp=dht.readTemperature();
hum=dht.readHumidity();

Serial.print("Temperatura:");
Serial.print(temp);
Serial.print("°C ");

Serial.print("Humedad:");
Serial.print(hum);
Serial.print("% ");
Serial.println();
delay(1000);
}
