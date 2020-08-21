/*
 * Gives control to the user via Blynk joysticks.
 * Will override current routine if the car is in auto mode.
 */
#include "ManualController.h"

ManualController::ManualController() {
  pinMode(MOTOR_POWER, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Turn on motor controller
  digitalWrite(MOTOR_POWER, HIGH);
}

void ManualController::turnCar(int turnDegrees) {
  servo.turn(turnDegrees);
}

void ManualController::driveCar(int newSpeed) {  
  driveSpeed = newSpeed;
  
  if (driveSpeed < 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  analogWrite(ENB, abs(driveSpeed));
}

void ManualController::checkDistance() {
  lastDistance = distance;
  distance = collisionDetector.getCM();
  
  if (lastDistance - distance > 100 && distance <= 30) {
    while (lastDistance - distance > 100) {
      this->driveCar(0);
      delay(50);
      lastDistance = distance;
      distance = collisionDetector.getCM();
    }
  }
}

//void ManualController::checkDistance() {
//  lastDistance = distance;
//  distance = collisionDetector.getCM();
//    
//  if (distance <= 100 && driveSpeed > 0) {
//    
//    Serial.println(lastDistance - distance);
//
//    if (distance <= 50) {
//      while (lastDistance - distance > 0) {
//        //driveSpeed = map(lastDistance - distance, 0, 200, 100, 200);
//        driveSpeed = 200;
//        //Serial.println(driveSpeed);
//        this->driveCar(-driveSpeed);
//        delay(50);
//        
//        lastDistance = distance;
//        distance = collisionDetector.getCM();
//      }
//
//      this->driveCar(0);
//    }
//  }
//}

