#include "ManualController.h"

ManualController::ManualController() {}

void ManualController::turnCar(int turnDegrees) {
  servo.turn(turnDegrees);
}

void ManualController::driveCar(int driveSpeed) {
  if (driveSpeed < 0) {
    digitalWrite(MOTOR_DIRECTION, HIGH);
    driveSpeed = abs(driveSpeed);
  } else {
    digitalWrite(MOTOR_DIRECTION, LOW);
  }

  analogWrite(MOTOR_DRIVE, driveSpeed);
}

