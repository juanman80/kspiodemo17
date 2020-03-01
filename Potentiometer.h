#ifndef MY_POTENTIOMETER_H
#define MY_POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer {
  
  protected:
    byte pin;

    int valMin;
    int valMax;

    void calibrate(int pos);
    virtual int doMap(int pos);
    
  public:
    Potentiometer();
    virtual void init(byte pot_pin);
    int readRaw();
    int readMap();
};

#endif