/***   Global variables   ***/
int led=13;
int boton=7;
int valor=0;
int contador=0;
int valor_anterior=0;

/***   Function declaration   ***/

void setup()
{





  Serial.begin(9600);

}


void loop()
{
    pinMode(boton,INPUT);
    valor=digitalRead(boton);
    if (valor == HIGH) {
      pinMode(led,OUTPUT);
      digitalWrite(led,HIGH);
      if (valor_anterior == LOW) {
        contador=contador + 1;
        Serial.println(contador);
       }
     }
    pinMode(led,OUTPUT);
    digitalWrite(led,LOW);
    valor_anterior=valor;
    valor=0;

}

/***   Function definition   ***/
