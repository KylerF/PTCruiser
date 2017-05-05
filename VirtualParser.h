#include "Arduino.h"
#include "ManualController.h"

class VirtualParser {
  ManualController manualController;
  
  public:
    VirtualParser();
    void vParse(int pin, int param);
};

