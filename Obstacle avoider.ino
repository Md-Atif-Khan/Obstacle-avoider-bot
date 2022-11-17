#include <Servo.h>
const int E1 = 9;
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 5;
const int RightMotorBackward = 4;
const int E2 = 3;
int trig_pin = 8;
int echo = 11;

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

Servo servo_motor;

void setup() {

  pinMode(trig_pin, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  Serial.begin(9600);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  Serial.println("HELLO");
  servo_motor.attach(10);

  servo_motor.write(90);
}

void loop() {
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20) {
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(500);
    if (distance >= distanceLeft) {
      turnRight();
      moveStop();
    }
    else {
      turnLeft();
      moveStop();
    }
  }
  else {
    moveForward();
  }
  distance = readPing();
}
int lookRight() {
  servo_motor.write(40);
  Serial.print("look right 40");
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  Serial.print("look right 90");
  return distance;
}

int lookLeft() {
  servo_motor.write(170);
  Serial.print("look left 170");
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  Serial.print("look right 90");
  return distance;
  delay(100);
}
int readPing() {
  delay(70);
  long y, cm;
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_pin, LOW);
  y = pulseIn(echo, HIGH);
  cm = (y / 2) / 29.1;
  Serial.println(cm);
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}

void moveStop() {

  analogWrite(E1, 125); // Run in half speed
  analogWrite(E2, 255); // Run in full speed
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward() {

  if (!goesForward) {

    goesForward = true;
    analogWrite(E1, 125); // Run in half speed
    analogWrite(E2, 255); // Run in full speed
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
  }
}

void moveBackward() {

  goesForward = false;
  analogWrite(E1, 125); // Run in half speed
  analogWrite(E2, 255); // Run in full speed
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnRight() {

  analogWrite(E1, 125); // Run in half speed
  analogWrite(E2, 255); // Run in full speed
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  delay(250);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
}
void turnLeft() {

  analogWrite(E1, 125); // Run in half speed
  analogWrite(E2, 255); // Run in full speed
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  delay(250);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
}

void turnLeftDirection() {
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  delay(300);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void turnRightDirection() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  delay(300);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void turnRightDirectionForCircle() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  delay(30);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
