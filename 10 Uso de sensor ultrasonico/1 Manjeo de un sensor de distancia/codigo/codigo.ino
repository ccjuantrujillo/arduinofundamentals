long distancia;
long tiempo;

void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);//Trigger
  pinMode(4,INPUT);//Eco
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
  delay(1000);
}

