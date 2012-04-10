/*
  DachisRfidReader.cpp 
*/
#include "Arduino.h"
#include <SoftwareSerial.h>
#include "DachisRfidReader.h"

DachisRfidReader::DachisRfidReader(int rx, int tx) : serial(SoftwareSerial(rx,tx))
{
	_rx = rx;
	_tx = tx;
	setup();
}

void DachisRfidReader::setup()
{
	pinMode(_rx, INPUT);
	pinMode(_tx, OUTPUT);
	activate();
}

void DachisRfidReader::activate()
{
	digitalWrite(_tx, LOW);
}

void DachisRfidReader::deactivate()
{
	digitalWrite(_tx, HIGH);
}

int DachisRfidReader::readTag()
{
	activate();
	int val = 0;
	int bytesread = 0;
	serial.begin(2400);
	delay(1000);                       // wait for a second
		
	if (serial.available() > 0) {
		if((val = serial.read()) == 10) {   // check for header 
			bytesread = 0; 
			while (bytesread < 10) {  // read 10 digit code 
				//Serial.println("Reading tag...");
				val = serial.read(); 
				if((val == 10)||(val == 13)) {  // if header or stop bytes before the 10 digit reading 
					break;                       // stop reading 
				} 
				if(val==-1) { // Garbled char
					//Serial.println("Garbled char");
					break;
				}
				code[bytesread] = val;         // add the digit    
				bytesread++;                   // ready to read next digit  
			} 

			bytesread = 0; 
			deactivate();    // deactivate the RFID reader
			return 1;
		}
		else {
		  return 0;
		}
	}
	
	return 0;
}
