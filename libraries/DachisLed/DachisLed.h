/*
  DachisLed.h - Library for LED blinkin
*/
#ifndef DachisLed_h
#define DachisLed_h

#include "Arduino.h"
	  
class DachisLed
{
  public:
    DachisLed(int pin);
	void blink(int delayTime);
    void blinkSlow();
	void blinkFast();
  private:
    int _pin;
};

#endif
