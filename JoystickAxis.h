#ifndef MY_JOYSTICK_AXIS_H
#define MY_JOYSTICK_AXIS_H

#include <Arduino.h>
#include "Potentiometer.h"

class JoystickAxis: public Potentiometer {
  
  protected:
    const byte deadZone = 5;
    int valRest;

    int doMap(int pos);
    
  public:
    JoystickAxis();
    void init(byte axis_pin);
};

#endif