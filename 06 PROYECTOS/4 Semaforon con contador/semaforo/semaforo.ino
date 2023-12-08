int segmentos[10]={2,3,4,5,6,7,8,11,12,13};
int luces[3]={11,12,13};

int num0[7]={0,0,0,0,0,0,1};
int num1[7]={1,0,0,1,1,1,1};
int num2[7]={0,0,1,0,0,1,0};
int num3[7]={0,0,0,0,1,1,0};
int num4[7]={1,0,0,1,1,0,0};
int num5[7]={0,1,0,0,1,0,0};
int num6[7]={1,1,0,0,0,0,0};
int num7[7]={0,0,0,1,1,1,1};
int num8[7]={0,0,0,0,0,0,0};
int num9[7]={0,0,0,1,1,0,0};
int numVacio[7]={1,1,1,1,1,1,1};

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<10;i++){
    pinMode(segmentos[i],OUTPUT);
  }
}

void loop() {
  cambio_luz(11);
  secuencia();
  delay(1000);

  cambio_luz(12);
  secuencia_corta();
  delay(1000);

  cambio_luz(13);
  secuencia();
  delay(1000);
}

void cambio_luz(int luz) {
  for(int i=0;i<3;i++){
    digitalWrite(luces[i],1);
  }
  digitalWrite(luz,0);
}

void secuencia_corta() {
    verNumero(num3);
  verNumero(num2);
  verNumero(num1);
  verNumero(num0);
}

void secuencia() {
  verNumero(num9);
    verNumero(num8);
  verNumero(num7);
  verNumero(num6);
    verNumero(num5);
  verNumero(num4);
  verNumero(num3);
  verNumero(num2);
  verNumero(num1);
  verNumero(num0);
}

void verNumero(int numero[7]){
  for(int i=0;i<7;i++){
    digitalWrite(segmentos[i],numero[i]);
  }
  delay(1000);
}

