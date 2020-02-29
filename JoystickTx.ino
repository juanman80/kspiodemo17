#include "JoystickAxis.h"

// Arduino pin numbers
const int JoystickTxSwitch = 25; // digital pin connected to switch output
const int JoystickTxAxisX = 0; // analog pin connected to X output
const int JoystickTxAxisY = 1; // analog pin connected to Y output

JoystickAxis axisX(JoystickTxAxisX);
JoystickAxis axisY(JoystickTxAxisY);

void InitJoystickTx() {
  pinMode(JoystickTxSwitch, INPUT_PULLUP);
  // digitalWrite(JoystickTxSwitch, HIGH);

  axisX.init();
  axisY.init();
}

void getJoystickTx(){
  // update every second
  int milliseconds = millis() % 1000;
  switch ( milliseconds ){
    case 0:
    case 250:
    case 500:
    case 750:
      int posX = axisX.readRaw();
      int convX = axisX.readMap();
      
      int posY = axisY.readRaw();
      int convY = axisY.readMap();
      // debugJoystickTxAxis(
      //   posX,
      //   convX,
      //   axisX.rest
      // );

      debugJoystickTx(
        posX,
        posY,
        convX,
        convY
      );
      break;
  }
  if( digitalRead(JoystickTxSwitch) == LOW ){
    lcd.clear();
  }
}
