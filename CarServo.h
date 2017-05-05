#include "Arduino.h"
#include <Servo.h>

// Turning servo pin
#define SERVO_PIN 7

// Limits for turning radius
#define LOWER 45
#define UPPER 70

class CarServo {
  Servo servo;

  public:
    CarServo();
    void turn(int turnDegrees);
};
