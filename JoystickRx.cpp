#include "JoystickRx.h"

JoystickRx::JoystickRx(){}

void JoystickRx::init(byte axisX, byte axisY, byte axisZ, byte button1){
    JoystickTx::init(axisX, axisY, button1);
    this->axisZ.init(axisZ);
}

int JoystickRx::readZ(){
    return this->axisZ.readMap();
}