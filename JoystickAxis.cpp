#include "JoystickAxis.h"

/* PRIVATE */

void JoystickAxis::calibrateAxis(int pos){
  if ( pos < this->min ){
    this->min = pos;
  }

  if ( pos > this->max ){
    this->max = pos;
  }
}

/* PUBLIC */
JoystickAxis::JoystickAxis() {
}

void JoystickAxis::init(byte axis_pin) {
  this->pin  = axis_pin;
  this->min  = 500;
  this->max  = 500;
  this->rest = readRaw();
}

int JoystickAxis::readRaw() {
  return analogRead(this->pin);
}

int JoystickAxis::readMap() {
  int pos = readRaw();
  calibrateAxis(pos);
  
  int deltaRest = this->rest - pos;
  if ( abs(deltaRest) < this->deadZone ){
    return 0;
  }

  return map(pos,this->min,this->max,-1000,1000);
}