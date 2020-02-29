#include "JoystickAxis.h"

/* PRIVATE */

void JoystickAxis::calibrateAxis(int pos){
  if ( pos < min ){
    min = pos;
  }

  if ( pos > max ){
    max = pos;
  }
}

/* PUBLIC */
JoystickAxis::JoystickAxis(byte joystick_pin) {
  this->pin = joystick_pin;
}

void JoystickAxis::init() {
  min  = 500;
  max  = 500;
  rest = readRaw();
}

int JoystickAxis::readRaw() {
  return analogRead(pin);
}

int JoystickAxis::readMap() {
  int pos = readRaw();
  calibrateAxis(pos);
  
  int deltaRest = rest - pos;
  if ( abs(deltaRest) < deadZone ){
    return 0;
  }

  return map(pos,min,max,-1000,1000);
}