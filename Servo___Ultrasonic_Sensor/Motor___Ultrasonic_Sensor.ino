#include <Servo.h>
#define TRIGPIN  3  
#define ECHOPIN  2  
int angle = 0;
Servo servo;
 
void setup(){
 
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  servo.attach(8);
  servo.write(angle);
  
}
 
void loop(){    
    digitalWrite(TRIGPIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN, LOW);

    int time1 = pulseIn(ECHOPIN, HIGH);
    int distance = time1*0.034/2;
    if (distance*3  <= 180)
    {
      servo.write(distance*3); 
      Serial.print(distance*3);
      Serial.println("º");
      delay(20);
    } 
    else{
      servo.write(180);
    }               
  }
