#include <LiquidCrystal.h> 

LiquidCrystal lcd(3,4,7,8,11,12,13); 

int Left_motor_back=9;   //(IN1)
int Left_motor_go=5;     //(IN2)
int Right_motor_go=6;    //(IN3)
int Right_motor_back=10; //(IN4)

int Trig =A4;  //  Trig(P2.1)IN5
int Echo = A5;  // Echo(P2.0)IN6

int Distance = 0;

void setup()
{
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  lcd.begin(16,2);     
  
  pinMode(Left_motor_go,OUTPUT); 
  pinMode(Left_motor_back,OUTPUT); 
  pinMode(Right_motor_go,OUTPUT);
  pinMode(Right_motor_back,OUTPUT);  
}


void medir_distancia()   
{
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance/58;    
  Serial.print("Distancia:");     
  Serial.println(Fdistance);         
  Distance = Fdistance;
}  

void loop()
{
  run();
  medir_distancia();
  if((2<Distance)&(Distance<400))
  {
    lcd.home();        
    lcd.print("    Distancia: ");       
    lcd.setCursor(6,2); 
    lcd.print(Distance);       
    lcd.print("cm");        
  }
  else
  {
    lcd.home();        
    lcd.print("!!!Fuera de rango");       
  }
  delay(250);
  lcd.clear();
}

void run()     
{
  digitalWrite(Right_motor_go,HIGH);  
  digitalWrite(Right_motor_back,LOW);     
  analogWrite(Right_motor_go,150);
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);  
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,150);
  analogWrite(Left_motor_back,0);
}

void brake(int time)  
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  delay(time * 100);
}

void left()        
{
  digitalWrite(Right_motor_go,HIGH);	
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,175); 
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,LOW);   
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);
}

void spin_left(int time)        
{
  digitalWrite(Right_motor_go,HIGH);	
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,250); 
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,LOW);  
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,100);
  delay(time * 100);	
}

void right()        
{
  digitalWrite(Right_motor_go,LOW);   
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,175); 
  analogWrite(Left_motor_back,0);
}

void spin_right(int time)       
{
  digitalWrite(Right_motor_go,LOW);  
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,100);
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,100); 
  analogWrite(Left_motor_back,0);
  delay(time * 100); 
}

void back(int time)          
{
  digitalWrite(Right_motor_go,LOW);  
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,100);
  digitalWrite(Left_motor_go,LOW);  
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);
  analogWrite(Left_motor_back,150);
  delay(time * 100);     
}
