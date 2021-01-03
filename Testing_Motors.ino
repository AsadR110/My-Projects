
#include <EEPROM.h>
#include <AFMotor.h>
AF_DCMotor motor1(1); //TOP RIGHT
AF_DCMotor motor2(2); //TOP LEFT
AF_DCMotor motor3(3); //BOTTOM LEFT
AF_DCMotor motor4(4); //BOTTOM RIGHT
char Incoming_value = 0; // initialize the incoming the signal from the bluetooth as zero


void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
  Serial.begin(9600);
}

void forward() {
//  motor1.setSpeed(250);
//  motor2.setSpeed(250);
//  motor3.setSpeed(250);
//  motor4.setSpeed(250);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
}

void left() {
// Right motors (1&4) go forward and left motors (2&3) go backwards
//  motor1.setSpeed(250);
//  motor2.setSpeed(250);
//  motor3.setSpeed(250);
//  motor4.setSpeed(250);
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
}

void right() {
// Left motors (2&3) go forward and right motors (1&4) go backwards
//  motor1.setSpeed(250);
//  motor2.setSpeed(250);
//  motor3.setSpeed(250);
//  motor4.setSpeed(250);
  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD); 
  motor4.run(FORWARD);
  
}
void backward() {
//  motor1.setSpeed(250);
//  motor2.setSpeed(250);
//  motor3.setSpeed(250);
//  motor4.setSpeed(250);
  
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD); 
  motor4.run(BACKWARD);
  
}
void done() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE); // 
  motor4.run(RELEASE);
}
void loop() {
    if(Serial.available() > 0)
  {
    Incoming_value = Serial.read();
    Serial.print(Incoming_value);
    Serial.print('\n');
    if(Incoming_value == '1' )
      forward();
    else if(Incoming_value == '0')
      backward();
    else if(Incoming_value == '2')
      left(); 
    else if(Incoming_value == '3')
      right();  
     else if(Incoming_value == '4')
      done();  
  }


}
