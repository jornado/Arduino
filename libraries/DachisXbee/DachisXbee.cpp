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

int DachisXbee::transmitMessage(char* message)
{
	serial.println(message);
	return 1;
}

int DachisXbee::receiveMessage()
{
	
	char* tmp_message;
    if (serial.available()) {
		//tmp_message = serial.read();
        Serial.write("Got code!");
		Serial.write(serial.read());
		//message = tmp_message;  
		return 1;  	
    }
	else {
		return 0;
	}
	
/*	
	if (serial.available() > 0) {
		//if((val = serial.read()) == 10) {   // check for header 
		bytesread = 0; 
		while (val = serial.read()) {  // read 10 digit code 
			//val = serial.read(); 
			//if((val == 10)||(val == 13)) {  // if header or stop bytes before the 10 digit reading 
			//	break;                       // stop reading 
			//} 
			if(val==-1) { // Garbled char
				//Serial.println("Garbled");
			}
			else {
				message[bytesread] = val;         // add the digit  
				Serial.print("Got val: ");
				Serial.println(val);  
				Serial.println(message);
				bytesread++;                   // ready to read next digit  				
			}
		} 
			
		bytesread = 0; 
		Serial.println("receiveMessage: ");
		Serial.println(message);
		return 1;
			//}
		//else {
		 // return 0;
			//}
	}
	else {
		return 0;
	}
	*/
	
}
