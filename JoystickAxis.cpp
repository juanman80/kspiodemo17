#include "JoystickAxis.h"

/* PRIVATE */

void JoystickAxis::calibrateAxis(int pos){
  if ( pos < this->valMin ){
    this->valMin = pos;
  }

  if ( pos > this->valMax ){
    this->valMax = pos;
  }
}

/* PUBLIC */
JoystickAxis::JoystickAxis() {
}

void JoystickAxis::init(byte axis_pin) {
  this->pin     = axis_pin;
  this->valMin  = 500;
  this->valMax  = 500;
  this->valRest = readRaw();
}

int JoystickAxis::readRaw() {
  return analogRead(this->pin);
}

int JoystickAxis::readMap() {
  int pos = readRaw();
  calibrateAxis(pos);
  
  int deltaRest = this->valRest - pos;
  if ( abs(deltaRest) < this->deadZone ){
    return 0;
  }

  return map(pos,this->valMin,this->valMax,-1000,1000);
}