#include "Potentiometer.h"

/* PRIVATE */

void Potentiometer::calibrateAxis(int pos){
  if ( pos < this->min ){
    this->min = pos;
  }

  if ( pos > this->max ){
    this->max = pos;
  }
}

/* PUBLIC */
Potentiometer::Potentiometer() {
}

void Potentiometer::init(byte pot_pin) {
  this->pin  = pot_pin;
  this->min  = 500;
  this->max  = 500;
}

int Potentiometer::readRaw() {
  return analogRead(this->pin);
}

int Potentiometer::readMap() {
  int pos = readRaw();
  calibrateAxis(pos);

  return map(pos,this->min,this->max,0,1000);
}