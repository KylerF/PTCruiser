#include "VirtualParser.h"
#include "ManualController.h"

VirtualParser::VirtualParser() {}

void VirtualParser::vParse(int pin, int param) {
  ManualController manualController = ManualController();
  
  if (pin == 0) {
    manualController.turnCar(param);
  }
}


