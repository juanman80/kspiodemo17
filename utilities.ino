void Indicators(Led SASLed) {
  if ( ControlStatus(AGSAS) ){
    SASLed.on();
  } else {
    SASLed.off();
  }
  digitalWrite(RCSLED,ControlStatus(AGRCS));
}

void initLEDS() {
//  pinMode(GLED,OUTPUT);
//  digitalWrite(GLED,HIGH);
//
//  pinMode(YLED,OUTPUT);
//  digitalWrite(YLED,HIGH);
//
//  pinMode(RLED,OUTPUT);
//  digitalWrite(RLED,HIGH);
  
  pinMode(RCSLED,OUTPUT);
  digitalWrite(RCSLED,HIGH);
//  
//  pinMode(CG1LED,OUTPUT);
//  digitalWrite(CG1LED,HIGH);
}

void LEDSAllOff() {
//  digitalWrite(GLED,LOW);
//  digitalWrite(YLED,LOW);
//  digitalWrite(RLED,LOW);
  digitalWrite(RCSLED,LOW);
//  digitalWrite(CG1LED,LOW);
}

void InitTxPackets() {
  HPacket.id = 0;  
  CPacket.id = 101;
}
