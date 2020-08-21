#include "VirtualParser.h"

VirtualParser::VirtualParser() {
  
}

void VirtualParser::vParse(int pin, int param) {
  if (pin == 0) {
    //autoController.halt();
    manualController.turnCar(param);
  } else if (pin == 1) {
    //autoController.halt();
    manualController.driveCar(param);
  } else if (pin == 3) {
    //autoController.start(manualController);
  }
}

void VirtualParser::checkSensors() {
  //manualController.checkDistance();
}

