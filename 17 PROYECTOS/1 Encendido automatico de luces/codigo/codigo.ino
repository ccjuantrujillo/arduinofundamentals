int pinLDR = A1;
int pinLuz = 8;
int pinBoton = 9;
int valorBoton = 0;
int valorBoton_ant = 0;
int estado = 0;
int tiempo = 0;
int led = 0;
boolean esMediaNoche = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLDR,INPUT);
  pinMode(pinLuz,OUTPUT);
  pinMode(pinBoton,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valor = analogRead(pinLDR);
  valorBoton = digitalRead(pinBoton);
  Serial.println(valor);
  delay(300);
  
  //Obtengo estado del pulsador
  if(valorBoton==HIGH && valorBoton_ant==LOW){
    estado = 1 - estado;
    delay(5);
  }
  valorBoton_ant = valorBoton;
  
  //Encendido automatico de luces
  if(valor<200){//Se hace de noche y se enciende el alumbrado automatico
    encender();    
    delay(5000);
    esMediaNoche = true;  
  }
  else{//Las luces estan apagadas, es de dia o medianoche
    apagar();
    if(!esMediaNoche){//Es de dia
        if(estado==1){
          encender();
        }
        else{
          apagar();
        }
      }
    //Es medianoche no senso nada
  }
}

void encender(){  
  led = 1;
  digitalWrite(pinLuz,HIGH);
}

void apagar(){
  led = 0;
  digitalWrite(pinLuz,LOW);
}

