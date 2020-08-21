#pragma once

#include "Arduino.h"
#include <Servo.h>

// Turning servo pin
#define SERVO_PIN 6

// Buttons for callibration
#define LEFT_SWITCH 8
#define RIGHT_SWITCH 9

// Limits for turning radius
#define DEFAULT_LOWER 45
#define DEFAULT_UPPER 70

class CarServo {
  Servo servo;
  int lower;
  int upper;
  int mid;
  
  public:
    CarServo();
    void turn(int turnDegrees);
    void calibrate();
};

