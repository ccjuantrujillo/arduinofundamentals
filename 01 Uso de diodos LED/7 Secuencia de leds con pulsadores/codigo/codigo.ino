int saltar=0;
const int pul=3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pul,INPUT);
  for(int i=6;i<=13;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pul)==HIGH){
    saltar++;
    if(saltar>3){
      saltar = 0;
    }
    while(digitalRead(pul)==HIGH){}
  }

  Serial.println(saltar);
  switch(saltar){
    case 0:
      secuencia1();
      break;
    case 1:
      secuencia2();
      break;
    case 2:
      secuencia3();
      break;
    case 3:
      secuencia4();
      break;      
  }
}

  //Secuencia1
  void secuencia1(){
    for(int i=13;i>=6;i--){
      digitalWrite(i,HIGH);
      delay(80);
      digitalWrite(i,LOW);
    }
  }

  //Secuencia2
  void secuencia2(){
    int inicio=9;
    for(int j=1;j<=4;j++){
      for(int i=inicio;i<inicio+2*j;i++){
        digitalWrite(i,HIGH);
      }
      delay(80);
      for(int i=inicio;i<inicio+2*j;i++){
        digitalWrite(i,LOW);
      }      
      inicio--;
    }
  }

  void secuencia3(){
    for(int j=8;j>=1;j--){
      for(int i=5+j;i<=13;i++){
        digitalWrite(i,HIGH);
      }
      delay(80);
      for(int i=5+j;i<=13;i++){
        digitalWrite(i,LOW);
      }      
    }
  }

  void secuencia4(){
    for(int j=6;j<13;j=j+4){
      for(int i=j;i<j+4;i++){
        digitalWrite(i,HIGH);
      }
      delay(80);
      for(int i=j;i<j+4;i++){
        digitalWrite(i,LOW);
      }      
    }
  }

