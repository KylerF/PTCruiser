#include "Arduino.h"
#include <Servo.h>

class CarServo {
  Servo servo;

  public:
    CarServo(int servoPin);
    void turn(int turnDegrees);
};
