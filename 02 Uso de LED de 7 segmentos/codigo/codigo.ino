int segmentos[7]={2,3,4,5,6,7,8};
int num0[7]={1,1,1,1,1,1,0};
int num1[7]={0,1,1,0,0,0,0};
int num2[7]={1,1,0,1,1,0,1};
int num3[7]={1,1,1,1,0,0,1};
int num4[7]={0,1,1,0,0,1,1};
int num5[7]={1,0,1,1,0,1,1};
int num6[7]={0,0,1,1,1,1,1};
int num7[7]={1,1,1,0,0,0,0};
int num8[7]={1,1,1,1,1,1,1};
int num9[7]={1,1,1,0,0,1,1};

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<7;i++){
    pinMode(segmentos[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  verNumero(num0);
  verNumero(num1);
  verNumero(num2);
  verNumero(num3);
  verNumero(num4);
  verNumero(num5);
  verNumero(num6);
  verNumero(num7);
  verNumero(num8);
  verNumero(num9);
}

void verNumero(int numero[7]){
  for(int i=0;i<7;i++){
    digitalWrite(segmentos[i],numero[i]);
  }
  delay(1000);
  for(int i=0;i<7;i++){
    digitalWrite(segmentos[i],0);
  }  
  delay(1000);
}

