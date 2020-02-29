#include "JoystickTx.h"

// Arduino pin numbers
const int JoystickTxSwitch = 25; // digital pin connected to switch output
const int JoystickTxAxisX = 0; // analog pin connected to X output
const int JoystickTxAxisY = 1; // analog pin connected to Y output

JoystickTx joyTx;

void InitJoystickTx() {
  joyTx.init(JoystickTxAxisX, JoystickTxAxisY, JoystickTxSwitch);
}

void getJoystickTx(){
  if( joyTx.isPressed() ){
    lcd.clear();
    return;
  }
  // update every second
  int milliseconds = millis() % 1000;
  switch ( milliseconds ){
    case 0:
    case 250:
    case 500:
    case 750:
      debugJoystickTx(
        0,
        0,
        joyTx.readX(),
        joyTx.readY()
      );
      break;
  }
}
