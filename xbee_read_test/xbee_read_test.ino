#include <SoftwareSerial.h>
#include <DachisLed.h>
#include <DachisXbee.h>

#define ledPin 13
#define xbeeRx 2
#define xbeeTx 3

DachisLed led(ledPin);
DachisXbee xbee(xbeeRx, xbeeTx);

void setup() {
  xbee.setup();
  led.blinkSlow();
  Serial.begin(9600);
  Serial.println("Xbee read test");
}

void loop() {

  if (xbee.receiveMessage()) {
    led.blinkSlow();
    Serial.println("Got code!");
    Serial.println(xbee.message);
  }
 
}

