#include "pin_config.h"

// This file is modified to use the Adafruit Motor shield

const uint8_t spdBoost = 0;
const uint8_t turnTime = 0;

void MotorsInit() {
  AFMS.begin();
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  /*
  pinMode(leftMotorPinA, OUTPUT);
  pinMode(leftMotorPinB, OUTPUT);
  pinMode(rightMotorPinA, OUTPUT);
  pinMode(rightMotorPinB, OUTPUT);*/
  
}

void rightMotorForward(uint8_t spd) {
  rightMotor->setSpeed(spd);
  rightMotor->run(FORWARD);
  //analogWrite(rightMotorPinA, spd);
  //digitalWrite(rightMotorPinB, LOW);
}

void rightMotorBackward(uint8_t spd) {
  rightMotor->setSpeed(spd);
  rightMotor->run(BACKWARD);
  // digitalWrite(rightMotorPinA, LOW);
  //analogWrite(rightMotorPinB, spd);
}

void rightMotorOff() {
  rightMotor->run(RELEASE);
  
  //digitalWrite(rightMotorPinA, LOW);
  //digitalWrite(rightMotorPinB, LOW);
}

void leftMotorForward(uint8_t spd) {
  leftMotor->setSpeed(spd);
  leftMotor->run(FORWARD);
  //analogWrite(leftMotorPinA, spd);
  //digitalWrite(leftMotorPinB, LOW);
}

void leftMotorBackward(uint8_t spd) {
  leftMotor->setSpeed(spd);
  leftMotor->run(BACKWARD);
  //digitalWrite(leftMotorPinA, LOW);
  //analogWrite(leftMotorPinB, spd);
}

void leftMotorOff() {
  leftMotor->run(RELEASE);
  //digitalWrite(leftMotorPinA, LOW);
  //digitalWrite(leftMotorPinB, LOW);
}

void RunMotors(int16_t leftSpd, int16_t rightSpd) {
  uint8_t leftSpdMotor;
  uint8_t rightSpdMotor;
  
  // Left forward
  if(leftSpd >= 0) {
    leftSpd += spdBoost;
    if(leftSpd > 255) {
      leftSpdMotor = 255;
    }
    else {
      leftSpdMotor = leftSpd;
    }
    leftMotorForward(leftSpdMotor);
  }
  // Left backward
  else if(leftSpd < 0) {
    leftSpd -= spdBoost;
    if(abs(leftSpd) > 255) {
      leftSpdMotor = 255;
    }
    else {
      leftSpdMotor = abs(leftSpd);
    }
    leftMotorBackward(leftSpdMotor);
  }

    // Right forward
  if(rightSpd >= 0) {
    rightSpd += spdBoost;
    if(rightSpd > 255) {
      rightSpdMotor = 255;
    }
    else {
      rightSpdMotor = rightSpd;
    }
    rightMotorForward(rightSpdMotor);
  }
  // Right backward
  else if(rightSpd < 0) {
    rightSpd -= spdBoost;
    if(abs(rightSpd) > 255) {
      rightSpdMotor = 255;
    }
    else {
      rightSpdMotor = abs(rightSpd);
    }
    rightMotorBackward(rightSpdMotor);
  }

  if((rightSpd > 0) && (leftSpd < 0)) {
    delay(turnTime);
  }
  else if((rightSpd < 0) && (leftSpd > 0)) {
    delay(turnTime);
  }
}

void MotorsOff() {
  leftMotorOff();
  rightMotorOff();
}

