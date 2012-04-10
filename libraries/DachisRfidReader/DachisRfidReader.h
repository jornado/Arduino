/*
  DachisRfidReader.h - Library for reading RFID tags
  RFID Power to VCC, Enable to pin _tx, SOUT to pin _rx, Ground to GND
*/
#ifndef DachisRfidReader_h
#define DachisRfidReader_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class DachisRfidReader
{
  public:
    DachisRfidReader(int rx, int tx);
	void setup();
    int readTag();
	void activate();
	void deactivate();
	SoftwareSerial serial;
	char code[10];
  private:
    int _rx;
    int _tx;
};

#endif