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
LiquidCrystal lcd(53, 52, 51, 50, 49, 48);
byte prevRem = 10;

void InitDebug(){
  lcd.begin(16, 2);
}

void debugLedMatrix(byte lf, byte oxi, byte ec, byte mp){
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("lf: ");
  lcd.setCursor(4, 0);
  lcd.print(lf);
  lcd.setCursor(8, 0);
  lcd.print("oxi: ");
  lcd.setCursor(12, 0);
  lcd.print(oxi);

  lcd.setCursor(0, 1);
  lcd.print("ec: ");
  lcd.setCursor(4, 1);
  lcd.print(ec);
  lcd.setCursor(8, 1);
  lcd.print("mp: ");
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
