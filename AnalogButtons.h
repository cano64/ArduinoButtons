/*

  class for hookup of up to 8 buttons to one analog pin 
  using resistors as voltage dividers using this schematics
  only one button can be pressed at a time
            
  VCC <---+-[ R0 ]-+-[ R1 ]-+-[ R1 ]- ... +-[ Rn-1 ]-+--> GND
          |        |        |             |          |
         [B0]     [B1]     [B2]         [Bn-1]     [Rx]
    A <---+--------+--------+----- .... --+----------+
    
    the following should be observed 
    Ri = Rj for i, j from (0..n-1)
    Sum (Ri) for i from (0..n-1) = 10kOhm
    Rx = 10kOhm
    
    
*/

#ifndef ANALOGBUTTONS_H
#define ANALOGBUTTONS_H


#include "Arduino.h"
#include "Buttons.h"

class AnalogButtons: public Buttons {

  public:
    uint8_t pin;
    uint16_t t[8];
    
    AnalogButtons(uint8_t apin, uint16_t t0, uint16_t t1, uint16_t t2, uint16_t t3, uint16_t t4); // constructor for 5 buttons

    void init(uint16_t t0, uint16_t t1, uint16_t t2, uint16_t t3, uint16_t t4, uint16_t t5, uint16_t t6, uint16_t t7);
    uint8_t getState();
    
  private:
  
}; //end of class Buttons



#endif
