#include "Led.h"

Led::Led() {
}

void Led::init(byte led_pin) {
  this->pin = led_pin;
  pinMode(this->pin, OUTPUT);
  off();
}

void Led::on() {
  digitalWrite(this->pin, HIGH);
}

void Led::off() {
  digitalWrite(this->pin, LOW);
}