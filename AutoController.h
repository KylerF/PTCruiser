#pragma once

#include "Arduino.h"

class AutoController {
  public:
    AutoController();
    //MPUSensor mpuSensor;
    void start();
    void halt();
};

