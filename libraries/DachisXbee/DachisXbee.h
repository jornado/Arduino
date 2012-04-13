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
    int transmitMessage(char* message);
	int receiveMessage();
	SoftwareSerial serial;
	char message[10];
  private:
    int _rx;
    int _tx;
};

#endif
