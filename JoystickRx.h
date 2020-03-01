#ifndef MY_JOYSTICK_RX_H
#define MY_JOYSTICK_RX_H

#include <Arduino.h>
#include "JoystickAxis.h"
#include "JoystickTx.h"

class JoystickRx: public JoystickTx {
  
  protected:
    JoystickAxis axisZ;
    
  public:
    JoystickRx();

    void init(byte axisX, byte axisY, byte axisZ, byte button1);
    int readZ();
};

#endif