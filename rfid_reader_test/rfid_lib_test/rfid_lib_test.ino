#include <SoftwareSerial.h>
#include <DachisRfidReader.h>
#include <DachisXbee.h>
#include <DachisLed.h>

#define xbeeRx 2
#define xbeeTx 3
#define rxPin 8
#define txPin 9
#define ledPin 13

DachisLed led(ledPin);
DachisRfidReader rfid(rxPin, txPin);
DachisXbee xbee(xbeeRx, xbeeTx);

void setup() { 
  Serial.begin(9600);
  rfid.setup();
  xbee.setup();
  led.blinkSlow();
}

void loop() { 
  if (rfid.readTag() > 0) {
    Serial.println(rfid.code);
    xbee.transmitMessage(rfid.code);
    led.blinkSlow();
  }
}
