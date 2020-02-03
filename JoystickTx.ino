// Arduino pin numbers
const int JoystickTxSwitch = 25; // digital pin connected to switch output
const int JoystickTxAxisX = 0; // analog pin connected to X output
const int JoystickTxAxisY = 1; // analog pin connected to Y output

const byte deadZone = 2;

int JoystickTxAxisXMin;
int JoystickTxAxisXMax;
int JoystickTxAxisXRest;
int JoystickTxAxisYMin;
int JoystickTxAxisYMax;
int JoystickTxAxisYRest;

void InitJoystickTx() {
  pinMode(JoystickTxSwitch, INPUT);
  digitalWrite(JoystickTxSwitch, HIGH);
  
  JoystickTxAxisXMin=500;
  JoystickTxAxisXMax=500;
  JoystickTxAxisYMin=500;
  JoystickTxAxisYMax=500;

  JoystickTxAxisXRest = analogRead(JoystickTxAxisX);
  JoystickTxAxisYRest = analogRead(JoystickTxAxisY);
}

void calibrateAxis(int pos, int &pmin, int &pmax){
  if ( pos < pmin ){
    pmin = pos;
  }

  if ( pos > pmax ){
    pmax = pos;
  }
}

int mapAxis(int pos, int rest, int pmin, int pmax){
  int deltaRest = rest - pos;
  if ( abs(deltaRest) < deadZone ){
    return 0;
  }

  return map(pos,pmin,pmax,-1000,1000);
}

void getJoystickTx(){
  // update every second
  int milliseconds = millis() % 1000;
  switch ( milliseconds ){
    case 0:
    case 250:
    case 500:
    case 750:
      int posX = analogRead(JoystickTxAxisX);
      calibrateAxis(posX, JoystickTxAxisXMin, JoystickTxAxisXMax);
      int convX = mapAxis(posX, JoystickTxAxisXRest, JoystickTxAxisXMin, JoystickTxAxisXMax);
      
      int posY = analogRead(JoystickTxAxisY);
      calibrateAxis(posY, JoystickTxAxisYMin, JoystickTxAxisYMax);
      int convY = mapAxis(posY, JoystickTxAxisYRest, JoystickTxAxisYMin, JoystickTxAxisYMax);
      
      debugJoystickTx(
        posX,
        posY,
        convX,
        convY
      );
      break;
  }
}
