//bluetooth hc-05
int ledPin = 13; // usamos un pin de salida al LED
char state = 0;   // Variable lectrura dato seria

void setup() {
    pinMode(ledPin, OUTPUT);   //Declara pin de Salida
    digitalWrite(ledPin, LOW); //Normalmente Apagado
    Serial.begin(9600);
}
 
void loop() {
 
        if(Serial.available() > 0){
             state = Serial.read();
        } 
       
      
       if (state == 'E') {
       
           digitalWrite(ledPin, HIGH);

       }
      
       if (state == 'A')
       {
           digitalWrite(ledPin, LOW);

       }

}

