#include <Servo.h>
Servo ServoOne;
Servo ServoTwo;
Servo ServoThree;
Servo ServoFour; 
Servo ServoFive;
Servo ServoSix;
Servo servos[] = {ServoOne, ServoTwo, ServoThree, ServoFour, ServoFive, ServoSix};

//Pin of each servo:
int Servo_one_pin = 2;
int Servo_two_pin = 3;
int Servo_three_pin = 4;
int Servo_four_pin = 5;
int Servo_five_pin = 6;
int Servo_six_pin = 7;

//Closed angle of each servo:
int closed_servos[6] =  {0, //one
                         0, //two
                         0, //three
                         0, //four
                         0, //five
                         0};//six

//Opened angle of each servo:
int opened_servos[6] =  {180, //one
                         180, //two
                         180, //three
                         180, //four
                         180, //five
                         180};//six
//Frequency between each open-closure of the hand
int Frequency = 2000;

//Function that checks the flex status and sends the position to the servo
void WriteServo(int angle, Servo servo){
     servo.write(angle);
  }

void Close(){
  for(int i = 0; i >= 6; i++){
  WriteServo(closed_servos[i], servos[i]);
  }
}

void Open(){
  for(int i = 0; i >= 6; i++){
  WriteServo(opened_servos[i], servos[i]);
  }
}

void setup()
{
  pinMode(13, OUTPUT);
  ServoOne.attach(Servo_one_pin);
  ServoTwo.attach(Servo_two_pin);
  ServoThree.attach(Servo_three_pin);
  ServoFour.attach(Servo_four_pin);
  ServoFive.attach(Servo_five_pin);
  ServoFive.attach(Servo_six_pin);

  //starting sequence:
  Open();
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
}

void loop()
{
  Close();
  delay(Frequency);
  Open();
  delay(Frequency);
}
