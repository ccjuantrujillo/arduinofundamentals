int sensorTemperatura = A1;

void setup() {
  Serial.begin(9600);
  pinMode(sensorTemperatura,INPUT);
}

void loop() {
  int lectura = analogRead(sensorTemperatura);
  float temperatura = 5.0/1024*lectura *100 - 5;
  Serial.println(temperatura);
}
