/*
 * Car logic for manual control using the Blynk service.
 */

// Main drive motor pins
#define MOTOR_DIRECTION 3 // LOW = forward, HIGH = backward
#define MOTOR_DRIVE 4

#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>

#include "CarServo.h"
#include "VirtualParser.h"

CarServo servo;
VirtualParser parser;

char localAuth[] = "f7bbbf4d3f754bd1a09a4ae38a313487";

char ssid[] = "NETGEAR01";
char pass[] = "pitterpatter";

// Set up Blynk virtual pin interrupts
BLYNK_WRITE(V0) {
  int turnDegrees = param[0].asInt();
  servo.turn(turnDegrees);
}

BLYNK_WRITE(V1) {
  int driveSpeed = param[0].asInt();
  Serial.println(driveSpeed);

  if (driveSpeed < 0) {
    digitalWrite(MOTOR_DIRECTION, HIGH);
    driveSpeed = abs(driveSpeed);
  } else {
    digitalWrite(MOTOR_DIRECTION, LOW);
  }

  analogWrite(MOTOR_DRIVE, driveSpeed);
}

BLYNK_WRITE_DEFAULT() {
  int pin = request.pin;
  int vParam = param.asInt();

  parser.vParse(pin, vParam);
}


void setup()
{
  Serial.begin(9600);

  pinMode(MOTOR_DRIVE, OUTPUT);
  pinMode(MOTOR_DIRECTION, OUTPUT);

  servo.turn(57);
  
  // Connect to local server
  Blynk.begin(localAuth, ssid, pass, IPAddress(192,168,1,198));
}

void loop()
{
  Blynk.run();
}

