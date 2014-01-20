/*

*/


#include "MCP23S08Buttons.h"
#include <SPI.h>

#define MCP23S08_ADDRESS 0b01000000
#define MCP23S08_WRITE 0x00
#define MCP23S08_READ 0x01

#define MCP23S08_IODIR 0x00
#define MCP23S08_GPPU 0x06
#define MCP23S08_GPIO 0x09




MCP23S08Buttons::MCP23S08Buttons(uint8_t apinSS) : 
  Buttons(),
  pinSS(apinSS)
  
{
	
	digitalWrite(this->pinSS, HIGH);
	pinMode(this->pinSS, OUTPUT);
	SPI.begin();
	this->transfer(MCP23S08_ADDRESS|MCP23S08_WRITE, MCP23S08_GPPU, 0xFF); //set pullups
	this->transfer(MCP23S08_ADDRESS|MCP23S08_WRITE, MCP23S08_IODIR, 0xFF); //set as inputs
}


uint8_t MCP23S08Buttons::getState() {
  return this->transfer(MCP23S08_ADDRESS|MCP23S08_READ, MCP23S08_GPIO, 0xFF);
}


uint8_t MCP23S08Buttons::transfer(uint8_t addr, uint8_t reg, uint8_t data) {
	digitalWrite(this->pinSS, LOW);
	SPI.transfer(addr);
	SPI.transfer(reg);
	uint8_t result = SPI.transfer(data);
	digitalWrite(this->pinSS, HIGH);
	return result;
}

//