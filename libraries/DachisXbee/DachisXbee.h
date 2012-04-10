/*
  DachisXbee.h - Library for Xbeeing
  Directions here
*/
#ifndef DachisXbee_h
#define DachisXbee_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class DachisXbee
{
  public:
    DachisXbee(int rx, int tx);
	void setup();
    int transmit(char* message);
	SoftwareSerial serial;
  private:
    int _rx;
    int _tx;
};

#endif
