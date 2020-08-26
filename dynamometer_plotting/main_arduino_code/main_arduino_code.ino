//Dynamometer Code 
//By Asad Raza and Neil Entote

/*This code will basically output the following values in the
Serial Monitor:
PWM, RPM, Velocity, Acceleration, Torque, Power
*/

float const efficiency = 1;
float velocity = 0;
float currentVelocity = 0;
float previousVelocity = 0;
float acceleration = 0;
float torque = 0;
float power = 0;

// encoder code 
#define motorPin1 9
#define motorPin2 10
#define channelA 3
#define channelB 2

// encoder
volatile long encoderCount = 0;
int interval = 1000;
int currentMillis = 0;
int previousMillis = 0;

// motor direction
int direction = 1;
int directionCounter = 0;

// motor pwm
int motorIncrement = 1;
int motorPWM = 0;
int RPM = 0;


void setup() {
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(channelA, INPUT_PULLUP);
  pinMode(channelB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(channelA), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(channelB), updateEncoder, CHANGE);
  previousMillis = millis();
}

void loop() {
  // motor control
  motorPWM += motorIncrement;
  if (direction == 1) {
    if (motorPWM == 255 || motorPWM == 0) {
    motorIncrement = -motorIncrement;
      directionCounter++;
    } 
    analogWrite(motorPin1, motorPWM);
  } 
  else {
    if (motorPWM == 255 || motorPWM == 0) {
      motorIncrement = -motorIncrement;
      directionCounter++;
    } 
    analogWrite(motorPin2, motorPWM);
  }
  
  if (directionCounter == 2) {
    directionCounter = 0;
    direction = -direction;
  }
  delay(500);

  // calculations
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    int current = analogRead(A0); //Replace A0 with current pin
    // current conversion formula
    int voltage = analogRead(A1); //Replace A1 with proper voltage Pin
    // voltage conversion formula 

    // PWM and RPM
    RPM = (encoderCount * 60 / 910);
    Serial.print(motorPWM);
    Serial.print(',');
    if (direction == 1) {
      Serial.print(RPM);
      Serial.print(',');
    } else {
      RPM = -RPM;
      Serial.print(RPM);
      Serial.print(',');
    }
    encoderCount = 0;

    // Velocity and Acceleration
    previousVelocity = velocity;
    velocity = (2 * PI * RPM) / 60; // in seconds
    currentVelocity = velocity;
    Serial.print(velocity);
    Serial.print(',');    

    acceleration = currentVelocity - previousVelocity;
    Serial.print(acceleration);
    Serial.print(','); 

    // Torque 
    // retrieve current and voltage from current sensor
    // efficiency defined above
    torque = (current * voltage * efficiency * 60) / (2 * PI * RPM);
    Serial.print(torque);
    Serial.print(','); 

    // Power Graphs
    // retrieve current and voltage from current sensor
    power = current * voltage* efficiency;
    Serial.println(power);
  }
}
  
void updateEncoder() {
  encoderCount++;
}
