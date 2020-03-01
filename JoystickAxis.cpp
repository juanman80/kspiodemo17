#include "JoystickAxis.h"

/* PRIVATE */

int JoystickAxis::doMap(int pos){
  int deltaRest = this->valRest - pos;
  if ( abs(deltaRest) < this->deadZone ){
    return 0;
  }

  return map(pos,this->valMin,this->valMax,-1000,1000);
}

/* PUBLIC */
JoystickAxis::JoystickAxis() {
}

void JoystickAxis::init(byte axis_pin) {
  Potentiometer::init(axis_pin);
  this->valRest = readRaw();
}
