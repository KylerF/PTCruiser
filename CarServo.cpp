#include "CarServo.h"

CarServo::CarServo() {
  servo.attach(SERVO_PIN);
}

void CarServo::turn(int turnDegrees) {
  // Limit to values specified in header
  //turnDegrees = constrain(turnDegrees, LOWER, UPPER);
  servo.write(turnDegrees);
}

