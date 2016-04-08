#include <Servo.h>

Servo servo; 

int ch2;
int ch3;
int ch4;
int ch5;

int val=0;
    
int fadeAmount = 2;
void setup() {

  
  pinMode(9, INPUT);
  pinMode(10, INPUT);

 servo.attach(3);
  
  pinMode(6,OUTPUT); 
  pinMode(7,OUTPUT); 
  pinMode(11,OUTPUT); 
  pinMode(12,OUTPUT); 
  pinMode(2,OUTPUT); 

  Serial.begin(9600); 

}

void loop() {
  ch2 = pulseIn(9, HIGH, 25000);
  ch3 = pulseIn(10, HIGH, 25000);
  ch4 = pulseIn(5, HIGH, 25000);
  ch5 = pulseIn(4, HIGH, 25000);
  
  if(ch2 > 1550 && ch2 < 2000) {
    digitalWrite(6,HIGH);
  }

  else if(ch2 < 1350 && ch2 > 1000) {
    digitalWrite(7,HIGH);
  }

  else{
    digitalWrite(6,LOW); 
    digitalWrite(7,LOW); 
  }

   
    if(ch3 > 1550 && ch3 < 2000) {
    digitalWrite(11,HIGH);
  }

  else if(ch3 < 1200 && ch3 > 900) {
    digitalWrite(12,HIGH);
  }

  else{
    digitalWrite(11,LOW); 
    digitalWrite(12,LOW); 
  }


  if(ch4 > 1130) {
  analogWrite(2,ch4/4.22); 
  }
  else if(ch4 < 1130) {
    digitalWrite(2,LOW);
  }

  servo.write(ch5);
 
  delay(50); 
}
