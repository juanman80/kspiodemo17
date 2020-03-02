void Indicators() {
  if ( ControlStatus(AGSAS) ){
    SASled.on();
  } else {
    SASled.off();
  }
  if ( ControlStatus(AGRCS) ){
    RCSled.on();
  } else {
    RCSled.off();
  }
}

void LEDSAllOff() {
  SASled.off();
  RCSled.off();
}

void InitTxPackets() {
  HPacket.id = 0;  
  CPacket.id = 101;
}
