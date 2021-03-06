/*

  class for hookup of up to 8 buttons to 8 digital pins

  Digital Pin A <-- [BTN A] --> GND
  Digital Pin B <-- [BTN B] --> GND
  Digital Pin C <-- [BTN C] --> GND
  Digital Pin D <-- [BTN D] --> GND
  Digital Pin E <-- [BTN E] --> GND
    
  internal pullups are used  
*/

#ifndef DIGITALBUTTONS_H
#define DIGITALBUTTONS_H


#include "Arduino.h"
#include "Buttons.h"

#define PIN_NOT_DEFINED 255

class DigitalButtons: public Buttons {

  public:
    uint8_t pins[8];
    
    DigitalButtons(uint8_t p0, uint8_t p1 = PIN_NOT_DEFINED, uint8_t p2 = PIN_NOT_DEFINED, uint8_t p3 = PIN_NOT_DEFINED, uint8_t p4 = PIN_NOT_DEFINED, uint8_t p5 = PIN_NOT_DEFINED, uint8_t p6 = PIN_NOT_DEFINED, uint8_t p7 = PIN_NOT_DEFINED); 

    void init(uint8_t p0, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6, uint8_t p7);
    uint8_t getState();
    
  private:
  
}; //end of class Buttons



#endif
