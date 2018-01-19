/***   Global variables   ***/
int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=8;

/***   Function declaration   ***/
void numero0 ();
void numero1 ();
void numero2 ();
void numero3 ();
void numero4 ();

void setup()
{









}


void loop()
{
    numero0();
    delay(500);
    numero1();
    delay(500);
    numero2();
    delay(500);
    numero3();
    delay(500);
    numero4();
    delay(500);

}

/***   Function definition   ***/
void numero0 () {
  pinMode(a,OUTPUT);
  digitalWrite(a,HIGH);
  pinMode(b,OUTPUT);
  digitalWrite(b,HIGH);
  pinMode(c,OUTPUT);
  digitalWrite(c,HIGH);
  pinMode(d,OUTPUT);
  digitalWrite(d,HIGH);
  pinMode(e,OUTPUT);
  digitalWrite(e,HIGH);
  pinMode(f,OUTPUT);
  digitalWrite(f,HIGH);
  pinMode(g,OUTPUT);
  digitalWrite(g,LOW);
 }
void numero1 () {
  pinMode(a,OUTPUT);
  digitalWrite(a,LOW);
  pinMode(b,OUTPUT);
  digitalWrite(b,HIGH);
  pinMode(c,OUTPUT);
  digitalWrite(c,HIGH);
  pinMode(d,OUTPUT);
  digitalWrite(d,LOW);
  pinMode(e,OUTPUT);
  digitalWrite(e,LOW);
  pinMode(f,OUTPUT);
  digitalWrite(f,LOW);
  pinMode(g,OUTPUT);
  digitalWrite(g,LOW);
 }
void numero2 () {
  pinMode(a,OUTPUT);
  digitalWrite(a,HIGH);
  pinMode(b,OUTPUT);
  digitalWrite(b,HIGH);
  pinMode(c,OUTPUT);
  digitalWrite(c,LOW);
  pinMode(d,OUTPUT);
  digitalWrite(d,HIGH);
  pinMode(e,OUTPUT);
  digitalWrite(e,HIGH);
  pinMode(f,OUTPUT);
  digitalWrite(f,LOW);
  pinMode(g,OUTPUT);
  digitalWrite(g,HIGH);
 }
void numero3 () {
  pinMode(a,OUTPUT);
  digitalWrite(a,HIGH);
  pinMode(b,OUTPUT);
  digitalWrite(b,HIGH);
  pinMode(c,OUTPUT);
  digitalWrite(c,HIGH);
  pinMode(d,OUTPUT);
  digitalWrite(d,HIGH);
  pinMode(e,OUTPUT);
  digitalWrite(e,LOW);
  pinMode(f,OUTPUT);
  digitalWrite(f,LOW);
  pinMode(g,OUTPUT);
  digitalWrite(g,HIGH);
 }
void numero4 () {
  pinMode(a,OUTPUT);
  digitalWrite(a,LOW);
  pinMode(b,OUTPUT);
  digitalWrite(b,HIGH);
  pinMode(c,OUTPUT);
  digitalWrite(c,HIGH);
  pinMode(d,OUTPUT);
  digitalWrite(d,LOW);
  pinMode(e,OUTPUT);
  digitalWrite(e,LOW);
  pinMode(f,OUTPUT);
  digitalWrite(f,HIGH);
  pinMode(g,OUTPUT);
  digitalWrite(g,HIGH);
 }
