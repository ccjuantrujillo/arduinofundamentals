int Left_motor_back=9;    //(IN1)
int Left_motor_go=5;      //(IN2)
int Right_motor_go=6;    //(IN3)
int Right_motor_back=10;  //(IN4)

void setup()
{
  pinMode(Left_motor_go,OUTPUT); 
  pinMode(Left_motor_back,OUTPUT); 
  pinMode(Right_motor_go,OUTPUT); 
  pinMode(Right_motor_back,OUTPUT);
}
void run(int time)    
{
  digitalWrite(Right_motor_go,HIGH); 
  digitalWrite(Right_motor_back,LOW);     
  analogWrite(Right_motor_go,200);
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH); 
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200);
  analogWrite(Left_motor_back,0);
  delay(time * 100);  
}

void brake(int time)        
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  delay(time * 100);
}

void left(int time)        
{
  digitalWrite(Right_motor_go,HIGH);	
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,LOW);   
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);
  delay(time * 100);	
}

void spin_left(int time)        
{
  digitalWrite(Right_motor_go,HIGH);	
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,LOW);   
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,200);
  delay(time * 100);	
}

void right(int time)       
{
  digitalWrite(Right_motor_go,LOW);   
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);
  delay(time * 100);	
}

void spin_right(int time)      
{
  digitalWrite(Right_motor_go,LOW);   
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,200);
  digitalWrite(Left_motor_go,HIGH);
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);
  delay(time * 100);	
}

void back(int time)        
{
  digitalWrite(Right_motor_go,LOW);  
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,150);
  digitalWrite(Left_motor_go,LOW);  
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);
  analogWrite(Left_motor_back,150);
  delay(time * 100);    
}

void loop()
{
  delay(2000); 
  back(10); 
  brake(5);
  run(10);
  brake(5);
  left(10);
  right(10);
  spin_right(20); 
  spin_left(20);
  brake(5);
}
