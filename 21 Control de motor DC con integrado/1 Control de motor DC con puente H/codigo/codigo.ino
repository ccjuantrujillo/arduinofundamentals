const int pinDireccion1 = 9;
const int pinDireccion2 = 10;
int pinPotenciometro = A0;
int pinVelocidad = 11;

int valor;

void setup() {
  Serial.begin(9600);
  pinMode(pinDireccion1,OUTPUT);
  pinMode(pinDireccion2,OUTPUT);
  digitalWrite(pinVelocidad,LOW);
}

void loop() {
  //Leo el valor del potenciometro
  valor = analogRead(pinPotenciometro)/4;

  //Giramos motor hacia la derecha
  digitalWrite(pinDireccion1,HIGH);
  digitalWrite(pinDireccion2,LOW);

  //Variamos la velocidad
  analogWrite(pinVelocidad,valor);
}
