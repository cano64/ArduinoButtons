/*

*/


#include "AnalogButtons.h"

AnalogButtons::AnalogButtons(uint8_t apin, uint16_t t0, uint16_t t1, uint16_t t2, uint16_t t3, uint16_t t4) : 
  Buttons(),
  pin(apin)
  
{
  this->init(t0, t1, t2, t3, t4, 0, 0, 0);
}

void AnalogButtons::init(uint16_t t0, uint16_t t1, uint16_t t2, uint16_t t3, uint16_t t4, uint16_t t5, uint16_t t6, uint16_t t7) {
  this->t[0] = t0;
  this->t[1] = t1;
  this->t[2] = t2;
  this->t[3] = t3;
  this->t[4] = t4;
  this->t[5] = t5;
  this->t[6] = t6;
  this->t[7] = t7;
}

uint8_t AnalogButtons::getState() {
  uint16_t a = analogRead(this->pin);
  uint8_t btn = 0b10000000;
  for (uint8_t i = 0; i < 8; i++) {
    if (this->t[i] == 0) return 0; //no button pressed
    if (a > this->t[i]) return btn;
    btn >>= 1;
  }
  return 0;
}


//