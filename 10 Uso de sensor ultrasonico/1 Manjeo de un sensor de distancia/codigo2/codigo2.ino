/***   Global variables   ***/
int distancia=0;
int tiempo=0;
int trigger=3;
int echo=4;

/***   Function declaration   ***/
//bqBAT
long TP_init(int trigger_pin, int echo_pin);
long Distance(int trigger_pin, int echo_pin);

void setup()
{





  Serial.begin(9600);

}


void loop()
{
    pinMode( echo , INPUT );
    pinMode( trigger , OUTPUT );
    distancia=Distance(trigger,echo);
    Serial.println(distancia);
    delay(1000);

}

/***   Function definition   ***/
//bqBAT
long TP_init(int trigger_pin, int echo_pin)
{
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  long microseconds = pulseIn(echo_pin ,HIGH);
  return microseconds;
}
long Distance(int trigger_pin, int echo_pin)
{
  long microseconds = TP_init(trigger_pin, echo_pin);
  long distance;
  distance = microseconds/29/2;
  if (distance == 0){
    distance = 999;
  }
  return distance;
}
