#include "Led.h"

int input(Led warning_led) {
  int returnValue = -1;
  now = millis();

  if (KSPBoardReceiveData()){
    deadtimeOld = now;
    returnValue = id;
    switch(id) {
    case 0: //Handshake packet
      Handshake(warning_led);
      break;
    case 1:
      Indicators(warning_led);
      break;
    }

    //We got some data, turn the green led on
//    digitalWrite(GLED,HIGH);
    Connected = true;
  }
  else
  { //if no message received for a while, go idle
    deadtime = now - deadtimeOld; 
    if (deadtime > IDLETIMER)
    {
      deadtimeOld = now;
      Connected = false;
      LEDSAllOff();
    }    
  }

  return returnValue;
}

byte ControlStatus(byte n)
{
  return ((VData.ActionGroups >> n) & 1) == 1;
}
