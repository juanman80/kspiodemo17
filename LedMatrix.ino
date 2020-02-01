//We always have to include the library
#include <LedControl.h>

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 24 is connected to the DataIn 
 pin 23 is connected to the CLK 
 pin 22 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(24,23,22,1);
byte lc_address = 0;

byte colLiquidFuel = 0;
byte colOxidizer   = 1;
byte colECharge    = 2;
byte colMonoProp   = 3;

void InitLedMatrix(){
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(lc_address,false);
  /* 
   *  Set the brightness to a min value 
   *  even so, it's quite bright
  */
  lc.setIntensity(lc_address,0);
  /* and clear the display */
  lc.clearDisplay(lc_address);
}

void fuelLedMatrix(){
  // update every second
  int milliseconds = millis() % 1000;
  if ( milliseconds == 0 ){
    byte qtyLiquidFuel = getLiquidFuelQty();
    byte qtyOxidizer   = getOxidizerQty();
    byte qtyECharge    = getEChargeQty();
    byte qtyMonoProp   = getMonoPropQty();
    
    displayFuel(colLiquidFuel, qtyLiquidFuel);
    displayFuel(colOxidizer,   qtyOxidizer);
    displayFuel(colECharge,    qtyECharge);
    displayFuel(colMonoProp,   qtyMonoProp);
    
    debugLedMatrix(qtyLiquidFuel, qtyOxidizer, qtyECharge, qtyMonoProp);
  }
}

byte getLiquidFuelQty(){
  float qty = VData.LiquidFuel * 8.0 / VData.LiquidFuelTot;
  return (byte) qty;
}

byte getOxidizerQty(){
  float qty = VData.Oxidizer * 8.0 / VData.OxidizerTot;
  return (byte) qty;
}

byte getEChargeQty(){
  float qty = VData.ECharge * 8.0 / VData.EChargeTot;
  return (byte) qty;
}

byte getMonoPropQty(){
  float qty = VData.MonoProp * 8.0 / VData.MonoPropTot;
  return (byte) qty;
}

/*
 * fuel between 0 and 3
 * qty between 0 and 8
 * (0 means no light at fuel gauge)
*/
void displayFuel(byte fuel, byte qty){
  byte col = 2 * fuel;
  byte heigth = qty;

  /* I think my matrix is on its side */
  lc.setRow(lc_address, col, (byte)0);
  lc.setRow(lc_address, col+1, (byte)0);

  for (byte c = col; c <= col+1; c++){
    for (byte r = 0; r < heigth; r++){
      lc.setLed(lc_address,c,r,true);
    }
  }
}
