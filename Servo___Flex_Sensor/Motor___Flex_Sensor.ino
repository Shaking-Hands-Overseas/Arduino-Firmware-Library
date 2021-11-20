#include <Servo.h>
int angle = 0;
Servo servo;
const int flex = A1;

void setup(){
 
  Serial.begin(9600);
  servo.attach(8);
  servo.write(angle);
  delay(20);
}
 
void loop(){
  
    int value1 = analogRead(flex);
    value1 = map(value, 700, 900, 0, 180);
    
    if (value  <= 180)
    {
      servo.write(value); 
      Serial.print(value);
      Serial.println("º");
      delay(20);
    } 
    else{
      servo.write(180);
      
    }               
  }
