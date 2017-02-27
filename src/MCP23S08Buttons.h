/*

  class for hookup of up to 8 buttons to MCP23S08 GPIO expander chip
  Wiring:
		MCP23S08 has internal pullups just connect one side of the button 
		to the GPIO pin and the other side ot the button to the GND
    


#ifndef MCP23S08Buttons_h
#define MCP23S08Buttons_h


#include "Arduino.h"
#include "Buttons.h"
#include <SPI.h>

class MCP23S08Buttons: public Buttons {

  public:
    uint8_t pinSS;
    
    MCP23S08Buttons(uint8_t apinSS); 
		
    uint8_t getState();
    uint8_t transfer(uint8_t addr, uint8_t reg, uint8_t data);
  private:
  
}; //end of class MCP23S08Buttons



#endif

*/
//