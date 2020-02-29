#ifndef MY_JOYSTICK_TX_H
#define MY_JOYSTICK_TX_H

#include <Arduino.h>
#include "Button.h"
#include "JoystickAxis.h"

class JoystickTx {
  
  private:
    JoystickAxis axisX;
    JoystickAxis axisY;
    Button button1;
    
  public:
    JoystickTx();

    void init(byte axisX, byte axisY, byte button1);
    int readX();
    int readY();
    bool isPressed();
    byte getState();
};

#endif