#pragma once

#include "Arduino.h"
#include "CarServo.h"
#include "CollisionDetector.h"

// Pin used to control power to motor circuits
#define MOTOR_POWER 7

// Main drive motor pins
#define ENB 3 // PWM speed
#define IN3 4
#define IN4 5

class ManualController {
  CarServo servo;
  CollisionDetector collisionDetector;
  int driveSpeed;
  int distance;
  int lastDistance;
  
  public:
    ManualController();
    void turnCar(int turnDegrees);
    void driveCar(int driveSpeed);
    void checkDistance();
};

