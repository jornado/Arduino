/*
  DachisXbee.cpp 
*/
#include "Arduino.h"
#include <SoftwareSerial.h>
#include "DachisXbee.h"

DachisXbee::DachisXbee(int rx, int tx) : serial(SoftwareSerial(rx,tx))
{
	_rx = rx;
	_tx = tx;
	setup();
}

void DachisXbee::setup()
{
	pinMode(_rx, INPUT);
	pinMode(_tx, OUTPUT);
	serial.begin(9600);
}

int DachisXbee::transmit(char* message)
{
	serial.println(message);
	return 1;
}
