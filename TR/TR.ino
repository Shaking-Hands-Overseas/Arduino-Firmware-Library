#include <Servo.h>
Servo ServoOne;
Servo ServoTwo;
Servo ServoThree;
Servo ServoFour;
Servo ServoFive;
int starting_angle = 0;
const int flexPin = A1;

void setup()
{
  ServoOne.attach(2);
  ServoTwo.attach(3);
  ServoThree.attach(4);
  ServoFour.attach(5);
  ServoFive.attach(6);
  ServoOne.write(starting_angle);
  ServoTwo.write(starting_angle);
  ServoThree.write(starting_angle);
  ServoFour.write(starting_angle);
  ServoFive.write(starting_angle); 
}

void loop()
{
  int value=analogRead(flexPin);
  int flex = map(value, 700, 900, 0, 180);
  ServoOne.write(flex);
  delay(50);
}
