#include "Button.h"
#include "JoystickAxis.h"
#include "JoystickTx.h"

JoystickTx::JoystickTx(){}

void JoystickTx::init(byte axisX, byte axisY, byte button1){
    this->axisX.init(axisX);
    this->axisY.init(axisY);
    this->button1.init(button1);
}

int JoystickTx::readX(){
    return this->axisX.readMap();
}
int JoystickTx::readY(){
    return this->axisY.readMap();
}
bool JoystickTx::isPressed() {
  return this->button1.isPressed();
}
byte JoystickTx::getState() {
  return this->button1.getState();
}