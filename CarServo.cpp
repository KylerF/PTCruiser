/*
 * Custom implementation of Servo for the car's front wheel turning servo.
 * Handles attaching the servo and degree calculations.
 * 
 */
#include "CarServo.h"

CarServo::CarServo() {
  int mid = (int) ((LOWER + UPPER) / 2);

  pinMode(SERVO_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
  servo.write(mid);
}

void CarServo::turn(int turnDegrees) {
  // Limit to values specified in header
  turnDegrees = constrain(turnDegrees, LOWER, UPPER);
  servo.write(turnDegrees);
}

