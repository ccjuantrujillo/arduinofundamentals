int Left_motor_back=9;   //(IN1)
int Left_motor_go=5;     //(IN2)
int Right_motor_go=6;    //(IN3)
int Right_motor_back=10; //(IN4)

const int SensorRight_2 = A4;   //(P3.5 OUT4)
const int SensorLeft_2 = A5;    //(P3.4 OUT3)

int SL_2;   
int SR_2;   

void setup()
{
  pinMode(Left_motor_go,OUTPUT); 
  pinMode(Left_motor_back,OUTPUT); 
  pinMode(Right_motor_go,OUTPUT);
  pinMode(Right_motor_back,OUTPUT);
  pinMode(key,INPUT);
  pinMode(beep,OUTPUT);
  pinMode(SensorRight_2, INPUT); 
  pinMode(SensorLeft_2, INPUT); 
}

void run()     
{
  digitalWrite(Right_motor_go,HIGH);  
  digitalWrite(Right_motor_back,LOW);     
  analogWrite(Right_motor_go,200);
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);  
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200);
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

void loop()
{
  while(1)
  {
    SR_2 = digitalRead(SensorRight_2);
    SL_2 = digitalRead(SensorLeft_2);
    if (SL_2 == HIGH&&SR_2==HIGH)
      run();   
    else if (SL_2 == HIGH & SR_2 == LOW)
        left();
    else if (SR_2 == HIGH & SL_2 == LOW) 
      right();
    else 
      back(15);
  }
}


