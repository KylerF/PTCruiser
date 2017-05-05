#include "CarServo.h"

CarServo::CarServo(int servoPin) {
  servo.attach(servoPin);
}

void CarServo::turn(int turnDegrees) {
  servo.write(turnDegrees);
}

