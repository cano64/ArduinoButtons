
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
    long timeLongWait; //how long to wait to generate Long* event
    
    //event handlers
    void (*onKeyPress)(uint8_t);
    void (*onKeyDown)(uint8_t);
    void (*onKeyUp)(uint8_t);
    void (*onKeyLongDown)(uint8_t);
    void (*onKeyLongUp)(uint8_t);
    
    
    void (*onStateChange)(uint8_t);
    
    
    Buttons(); //the constructor

    void update();
    uint8_t check();
    virtual uint8_t getState();
    
  private:
    uint8_t longFired;
}; //end of class Buttons



#endif
