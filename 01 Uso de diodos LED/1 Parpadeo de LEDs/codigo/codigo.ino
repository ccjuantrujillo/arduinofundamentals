/***   Global variables   ***/
int LED=13;

/***   Function declaration   ***/

void setup()
{



}


void loop()
{
    pinMode(LED,OUTPUT);
    digitalWrite(LED,HIGH);
    delay(500);
    pinMode(LED,OUTPUT);
    digitalWrite(LED,LOW);
    delay(500);

}
