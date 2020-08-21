#pragma once

#include "Arduino.h"
#include "ManualController.h"
#include "AutoController.h"

class VirtualParser {
  ManualController manualController;
  //AutoController autoController;
  
  public:
    VirtualParser();
    void vParse(int pin, int param);
    void checkSensors();
};

