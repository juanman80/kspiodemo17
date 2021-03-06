/*
 * The circuit:
 * LCD RS pin to digital pin 53
 * LCD Enable pin to digital pin 52
 * LCD D4 pin to digital pin 51
 * LCD D5 pin to digital pin 50
 * LCD D6 pin to digital pin 49
 * LCD D7 pin to digital pin 48
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K potentiometer:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 
 * Based on 
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
// LiquidCrystal lcd(53, 52, 51, 50, 49, 48);
byte prevRem = 10;

void InitDebug(){
  lcd.begin(16, 2);
}

void debugJoystickRx(int posX, int posY, int posZ){
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("pX:");
  lcd.setCursor(3, 0);
  lcd.print(posX);
  lcd.setCursor(8, 0);
  lcd.print("pY:");
  lcd.setCursor(11, 0);
  lcd.print(posY);

  lcd.setCursor(0, 1);
  lcd.print("pZ:");
  lcd.setCursor(3, 1);
  lcd.print(posZ);
}

void debugPotentiometerAndJoystickTx(int posX, int posY, int potRaw, int potMap){
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("tX:");
  lcd.setCursor(3, 0);
  lcd.print(posX);
  lcd.setCursor(9, 0);
  lcd.print("pR:");
  lcd.setCursor(12, 0);
  lcd.print(potRaw);

  lcd.setCursor(0, 1);
  lcd.print("tY:");
  lcd.setCursor(3, 1);
  lcd.print(posY);
  lcd.setCursor(9, 1);
  lcd.print("pM:");
  lcd.setCursor(12, 1);
  lcd.print(potMap);
}

void debugJoystickTx(int posX, int posY, int convX, int convY){
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("pX:");
  lcd.setCursor(3, 0);
  lcd.print(posX);
  lcd.setCursor(8, 0);
  lcd.print("cX:");
  lcd.setCursor(11, 0);
  lcd.print(convX);

  lcd.setCursor(0, 1);
  lcd.print("pY:");
  lcd.setCursor(3, 1);
  lcd.print(posY);
  lcd.setCursor(8, 1);
  lcd.print("cY:");
  lcd.setCursor(11, 1);
  lcd.print(convY);
}

void debugJoystickTxAxis(int pos, int conv, int mid){
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("p:");
  lcd.setCursor(2, 0);
  lcd.print(pos);
  
  lcd.setCursor(7, 0);
  lcd.print("m:");
  lcd.setCursor(9, 0);
  lcd.print(mid);

  lcd.setCursor(0, 1);
  lcd.print("c:");
  lcd.setCursor(2, 1);
  lcd.print(conv);
}

void debugLedMatrix(byte lf, byte oxi, byte ec, byte mp){
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("lf:");
  lcd.setCursor(4, 0);
  lcd.print(lf);
  lcd.setCursor(8, 0);
  lcd.print("oxi:");
  lcd.setCursor(12, 0);
  lcd.print(oxi);

  lcd.setCursor(0, 1);
  lcd.print("ec:");
  lcd.setCursor(4, 1);
  lcd.print(ec);
  lcd.setCursor(8, 1);
  lcd.print("mp:");
  lcd.setCursor(12, 1);
  lcd.print(mp);
}

void Debug(){
  int seconds = millis() / 1000;
  byte rem = seconds % 6;
  if (rem != prevRem){
    lcd.clear();
    prevRem = rem;
  }
  switch ( rem ){
    case 0:
    case 1:
      DebugNavMode();
      break;
    case 2:
    case 3:
      DebugLF();
      break;
    case 4:
    case 5:
      DebugSF();
      break;
  }
}

void DebugNavMode(){
  lcd.setCursor(0, 0);
  lcd.print("SAS:");
  lcd.setCursor(5, 0);
  lcd.print(ControlStatus(AGSAS));
  lcd.setCursor(0, 1);
  lcd.print("RCS:");
  lcd.setCursor(5, 1);
  lcd.print(ControlStatus(AGRCS));
}

void DebugLF(){
  lcd.setCursor(0, 0);
  lcd.print("LF_Tot:");
  lcd.setCursor(8, 0);
  lcd.print(VData.LiquidFuelTot);
  lcd.setCursor(0, 1);
  lcd.print("LF_Cur:");
  lcd.setCursor(8, 1);
  lcd.print(VData.LiquidFuel);
}

void DebugSF(){
  lcd.setCursor(0, 0);
  lcd.print("SF_Tot:");
  lcd.setCursor(8, 0);
  lcd.print(VData.SolidFuelTot);
  lcd.setCursor(0, 1);
  lcd.print("SF_Cur:");
  lcd.setCursor(8, 1);
  lcd.print(VData.SolidFuel);
}
