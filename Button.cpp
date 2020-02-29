#include "Button.h"

Button::Button() {
}

void Button::init(byte button_pin) {
  this->pin = button_pin;
  this->lastReading = LOW;
  pinMode(this->pin, INPUT_PULLUP);
  update();
}

//handles the debounce of the button directly
void Button::update() {
  byte newReading = digitalRead(this->pin);
  
  if (newReading != this->lastReading) {
    this->lastDebounceTime = millis();
  }

  if (millis() - this->lastDebounceTime > this->debounceDelay) {
    // Update the 'state' attribute only if debounce is checked
    this->state = newReading;
  }

  this->lastReading = newReading;
}

byte Button::getState() {
  update();
  return this->state;
}

bool Button::isPressed() {
  return (getState() == LOW);
}