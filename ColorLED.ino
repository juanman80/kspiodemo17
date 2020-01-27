#include <RGB_LED.h>

RGB_LED ElectricCLED(45, 44, 43);
//RGB_LED FuelCLED(42, 41, 40);
//RGB_LED PropCLED(39, 38, 37);

void initColorLEDS() {
  ElectricCLED.fadeToColour(Red,500);
}

void runColorLEDS(){
  ElectricCLED.run();
  ElectricCLED.fadeToColour(Red,500);
}
