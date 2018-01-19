int pinNotas[7] = {2,3,4,5,6,7,8};
int pinZumbador = 13;
int frecuencia[7] = {
  262, //Frecuencia de la nota DO
  294, //Frecuencia de la nota RE
  330, //Frecuencia de la nota MI
  349, //Frecuencia de la nota FA
  392, //Frecuencia de la nota SOL
  440, //Frecuencia de la nota LA
  494 //Frecuencia de la nota SI
};

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<7;i++){
    pinMode(pinNotas[i],INPUT);
  }
  pinMode(pinZumbador,OUTPUT);
}

void loop() {
  int valor=0;
  int pulsador_actual = 0;
  noTone(pinZumbador);  
  for(int i=0;i<7;i++){
    valor = digitalRead(pinNotas[i]);  
    if(valor==HIGH){
      tone(pinZumbador,frecuencia[i]);
      pulsador_actual = pinNotas[i];
      break;
    }
  }
  if(pulsador_actual==LOW){
    noTone(pinZumbador); 
  }
}
