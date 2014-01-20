

/*

*/

#ifndef BUTTONS_H
#define BUTTONS_H


#include "Arduino.h"

class Buttons {

  public: 

    unsigned char prevState;
    long timeLastChange;
    long timeLastKeyDown;
    long timeLastKeyRepeat;
    long timeDebounce;
    long repeatDelay; //delay between two repeats in ms
    long repeatWait; //delay between first key press and start repeating in ms
    
    //event handlers
    void (*onKeyPress)(uint8_t);
    void (*onKeyDown)(uint8_t);
    void (*onKeyUp)(uint8_t);
    void (*onStateChange)(uint8_t);
    
    
    Buttons(); //the constructor

    void update();
    uint8_t check();
    virtual uint8_t getState();
    
  private:
  
}; //end of class Buttons



#endif
