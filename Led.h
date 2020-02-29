#ifndef MY_LED_H
#define MY_LED_H

#include <Arduino.h>

class Led {
  
  private:
    byte pin;
    
  public:
    Led();
    void init(byte led_pin);
    void on();
    void off();
};

#endif