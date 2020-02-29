#ifndef MY_JOYSTICK_AXIS_H
#define MY_JOYSTICK_AXIS_H

#include <Arduino.h>

class JoystickAxis {
  
  private:
    byte pin;
    const byte deadZone = 5;

    int min;
    int max;
    int rest;

    void calibrateAxis(int pos);
    
  public:
    JoystickAxis();
    void init(byte axis_pin);
    int readRaw();
    int readMap();
};

#endif