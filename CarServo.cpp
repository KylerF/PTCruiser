#include "CarServo.h"

CarServo::CarServo() {
  int mid = (int) ((LOWER + UPPER) / 2);
  servo.attach(SERVO_PIN);
  servo.write(mid);
}

void CarServo::turn(int turnDegrees) {
  // Limit to values specified in header
  turnDegrees = constrain(turnDegrees, LOWER, UPPER);
  servo.write(turnDegrees);
}

