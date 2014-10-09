/*

*/


#include "DigitalButtons.h"

DigitalButtons::DigitalButtons(uint8_t p0, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6, uint8_t p7) : Buttons() {
  this->init(p0, p1, p2, p3, p4, p5, p6, p7);
}

void DigitalButtons::init(uint8_t p0, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6, uint8_t p7) {
  this->pins[0] = p0;
  this->pins[1] = p1;
  this->pins[2] = p2;
  this->pins[3] = p3;
  this->pins[4] = p4;
  this->pins[5] = p5;
  this->pins[6] = p6;
  this->pins[7] = p7;
  for (uint8_t i = 0; i < 8; i++) {
    if (this->pins[i] != PIN_NOT_DEFINED) { //pin is defined
    	pinMode(this->pins[i], INPUT);
    	digitalWrite(this->pins[i], HIGH); //enable pullup
    }
  }
}

uint8_t DigitalButtons::getState() {
  uint8_t btn = 0;
  for (uint8_t i = 0; i < 8; i++) {
    btn <<= 1;
    if (this->pins[i] != PIN_NOT_DEFINED) { //pin is defined
      if (!digitalRead(pins[i])) btn |= 0x01;
    }
  }
  return btn;
}


//
