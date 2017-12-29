int timer = 500;
int cant = 0;
int matriz[5]={9,10,11,12,13};
int pot = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1,INPUT);
  for(int i=0;i<cant;i++){
    pinMode(matriz[i],OUTPUT);
  }
}

void loop() {
  //Leemos la cantidad e leds
  cant = analogRead(pot)/200;
  Serial.println(cant);
  
  //Secuencia de leds
  for(int i=0;i<cant;i++){
    digitalWrite(matriz[i],HIGH);
    delay(timer);
    digitalWrite(matriz[i],LOW);
  }
  for(int i=cant-1;i>0;i--){
    digitalWrite(matriz[i],HIGH);
    delay(timer);
    digitalWrite(matriz[i],LOW);
  }
}
