#pragma once

#include "Arduino.h"
#include "CarServo.h"

// Main drive motor pins
#define MOTOR_DIRECTION 3 // LOW = forward, HIGH = backward
#define MOTOR_DRIVE 4

class ManualController {
  CarServo servo;
  
  public:
    ManualController();
    void turnCar(int turnDegrees);
    void driveCar(int driveSpeed);
};

