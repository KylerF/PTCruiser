#include "CollisionDetector.h"

CollisionDetector::CollisionDetector() {
  
}

int CollisionDetector::getCM() {
  NewPing sonar(PING_PIN, 0, 1000); 
  return sonar.ping_cm();
}

