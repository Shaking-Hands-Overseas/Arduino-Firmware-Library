#include <Servo.h>
Servo ServoOne;
Servo ServoTwo;
Servo ServoThree;
Servo ServoFour;
Servo ServoFive;
int starting_angle = 0;
const int flexOne = A1;
const int flexTwo = A2;
const int flexThree = A3;
const int flexFour = A4;
const int flexFive = A5;
//Frequency between updates
int Frequency = 50;

//Function that checks the flex status and sends the position to the servo
int WriteServo(const int flex, Servo servo){
     //Reading the input from the flex sensor:
     int flex_value=analogRead(flex);
     
     //Converting the input to degrees:
     int flex_value_map=map(flex_value, 700, 900, 0, 180);
     
     //Writting the position into the servo:
     servo.write(flex_value_map);
     return 0;
     
  }

void setup()
{
  pinMode(13, OUTPUT);
  ServoOne.attach(2);
  ServoTwo.attach(3);
  ServoThree.attach(4);
  ServoFour.attach(5);
  ServoFive.attach(6);
  //Starting sequence:
  ServoOne.write(starting_angle);
  ServoTwo.write(starting_angle);
  ServoThree.write(starting_angle);
  ServoFour.write(starting_angle);
  ServoFive.write(starting_angle); 
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
}

void loop()
{
  WriteServo(flexOne, ServoOne);
  WriteServo(flexTwo, ServoTwo);
  WriteServo(flexThree, ServoThree);
  WriteServo(flexFour, ServoFour);
  WriteServo(flexFive, ServoFive);
  delay(Frequency);
}
