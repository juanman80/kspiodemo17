#include "Potentiometer.h"

/* PRIVATE */

void Potentiometer::calibrate(int pos){
  if ( pos < this->valMin ){
    this->valMin = pos;
  }

  if ( pos > this->valMax ){
    this->valMax = pos;
  }
}

int Potentiometer::doMap(int pos){
  return map(pos,this->valMin,this->valMax,0,1000);
}

/* PUBLIC */
Potentiometer::Potentiometer() {
}

void Potentiometer::init(byte pot_pin) {
  this->pin     = pot_pin;
  this->valMin  = 500;
  this->valMax  = 500;
}

int Potentiometer::readRaw() {
  return analogRead(this->pin);
}

int Potentiometer::readMap() {
  int pos = readRaw();
  calibrate(pos);
  return doMap(pos);
}