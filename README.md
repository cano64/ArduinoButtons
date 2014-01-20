ArduinoButtons
------------

ArduinoButtons is an event driven library to control multiple buttons, It supports various wiring methods, debouncing and autorepeat.

Wiring methods
------------
	*Multiple buttons conencted to one analog pin using resistor voltage divider
	*Multiple buttons connected to MCP23S08 SPI port expander
	*Multiple capacitive buttons conencted to one feed pin and multiple receive pins (TODO)
	*Multiplex matrix buttons (TODO)
	*Multiple buttons connected to multiple diginal pins with internal or external pullups (TODO)
	
Events
------

	*onKeyDown
	*onKeyUp
	*onKeyPress (with autorepeat)
	*onHold (TODO)
	
	
Usage
-----

	AnalogButtons buttons(6, 836, 544, 368, 228, 80);


	/***** EVENT HANDLERS ******/  

	void onKeyPress(uint8_t btn) {
		//you pressed the button number btn
	}

	/***** SETUP ******/  

	void setup() {
		buttons.onKeyPress = onKeyPress;
	}

	/***** LOOP ******/  

	void loop() {
		buttons.update();
	}	
	
