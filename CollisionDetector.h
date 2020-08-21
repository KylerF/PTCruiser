#pragma once

#include "Arduino.h"
#include <NewPing.h>

#define PING_PIN 0

class CollisionDetector { 
  public:
    CollisionDetector();
    int getCM();
};



