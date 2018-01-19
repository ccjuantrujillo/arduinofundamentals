String mensaje = "AAEUO";
String abecedario ="AEIOU ";
byte matriz[8][8] = {
  {B00000000,B00111100,B00100100,B00100100,B00111100,B00100100,B00100100,B00000000},  //A
  {B00000000,B00111100,B00100000,B00111000,B00100000,B00111100,B00000000,B00000000},  //E
  {B00000000,00111100,00100100,00100100,00111100,00100100,00100100,00000000},  //I
  {B00000000,00111100,00100100,00100100,00111100,00100100,00100100,00000000},  //O
  {B00000000,00111100,00100100,00100100,00111100,00100100,00100100,00000000},  //U
  { 0x78, 0x44, 0x44, 0x78, 0x40, 0x40, 0x40, 0x40 }, //P
  { 0x78, 0x44, 0x44, 0x78, 0x70, 0x58, 0x4C, 0x46 }, //R
  { 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C }  //O
};
int fila[8] = {10,11,12,13,A1,A2,A3,A4};
int columna[8] = {2,3,4,5,6,7,8,9};

void setup() {
  Serial.begin(9600);
  for(int i=0;i<8;i++){
    pinMode(fila[i],OUTPUT);
    pinMode(columna[i],OUTPUT);
  }
}

void loop() {
  int tamano = mensaje.length();
  for(int i=0;i<tamano;i++){
    int pos = abecedario.indexOf(mensaje[i]);//fila
    dibujar(pos);
    delay(1000);
    apagar();
  }
}

void efectos(){
  encender();
  delay(1000);
  apagar();
  delay(1000);
  cortinav();
  apagar();
  delay(1000);
  cortinah();
  apagar();  
  delay(1000);
  seguidor();
}

void limpiar(){
  for(int i=0;i<8;i++){
    columna[i]=0;
    fila[i]=0;
  }
}

void encender(){
  for(int i=0;i<8;i++){
    digitalWrite(fila[i],HIGH);
    for(int j=0;j<8;j++){
      digitalWrite(columna[i],LOW);
    }
  }
}

void apagar(){
  for(int i=0;i<8;i++){
    digitalWrite(fila[i],LOW);
    for(int j=0;j<8;j++){
      digitalWrite(columna[i],HIGH);
    }
  }
}

void cortinav(){
  for(int i=0;i<8;i++){
    digitalWrite(fila[i],HIGH);
    for(int j=0;j<8;j++){
      digitalWrite(columna[j],LOW);
    }
    delay(500);
  }
}

void cortinah(){
  for(int j=0;j<8;j++){
    digitalWrite(columna[j],LOW);
    for(int i=0;i<8;i++){
      digitalWrite(fila[i],HIGH);
    }
    delay(500);
  }
}

void seguidor(){
  for(int i=0;i<8;i++){
      digitalWrite(fila[i],HIGH);
      for(int j=0;j<8;j++){
        digitalWrite(columna[j],LOW);  
        delay(500);
        digitalWrite(columna[j],HIGH);  
      }
      digitalWrite(fila[i],LOW);
  }
}

void dibujar(int p){
  int n;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      n = matriz[p][i]>>j;
      n = n&1;
      if(n==1){
        digitalWrite(fila[i],HIGH);
        digitalWrite(columna[j],LOW);
      }
      else{
        digitalWrite(fila[i],LOW);
        digitalWrite(columna[j],HIGH);
      }
    }
  }
  delay(5);
}

