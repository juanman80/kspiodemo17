#ifndef MY_POTENTIOMETER_H
#define MY_POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer {
  
  private:
    byte pin;

    int valMin;
    int valMax;

    void calibrateAxis(int pos);
    
  public:
    Potentiometer();
    void init(byte pot_pin);
    int readRaw();
    int readMap();
};

#endif