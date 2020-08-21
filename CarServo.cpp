/*
 * Custom implementation of Servo for the car's front wheel turning servo.
 * Handles attaching the servo and degree calculations.
 * 
 * FUTURE: Auto calibration when instantiated
 * 
 */
#include "CarServo.h"

CarServo::CarServo() {
  this->calibrate();

  pinMode(SERVO_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
  servo.write(mid);
}

void CarServo::turn(int turnDegrees) {
  // Limit to values specified in header
  turnDegrees = map(turnDegrees, -100, 100, lower, upper);
  servo.write(turnDegrees);
}

void CarServo::calibrate() {
  lower = DEFAULT_LOWER;
  upper = DEFAULT_UPPER;
  
  mid = (int) ((lower + upper) / 2);
}

