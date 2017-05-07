#include "VirtualParser.h"

VirtualParser::VirtualParser() {}

void VirtualParser::vParse(int pin, int param) {
  if (pin == 0) {
    manualController.turnCar(param);
  } else if (pin == 1) {
    manualController.driveCar(param);
  }
}

