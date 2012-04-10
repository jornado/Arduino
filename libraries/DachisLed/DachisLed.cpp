/*
  DachisLed.cpp 
*/
#include "Arduino.h"
#include "DachisLed.h"

DachisLed::DachisLed(int pin)
{
	_pin = pin;
}

void DachisLed::blink(int delayTime)
{
	digitalWrite(_pin, HIGH);  
	delay(delayTime);              
	digitalWrite(_pin, LOW);
	delay(delayTime);
}

void DachisLed::blinkSlow()
{
	blink(1000);
}

void DachisLed::blinkFast()
{
	blink(100);
}

