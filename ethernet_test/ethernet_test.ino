#include <Ethernet.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <DachisLed.h>
#include <DachisXbee.h>

#define ledPin 13
#define xbeeRx 2
#define xbeeTx 3

byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0xFC, 0xF1};
byte ip[] = { 10, 251, 8, 32 };
byte server[] = { 107, 20, 184, 48 }; // dgpdx

EthernetClient client;
DachisLed led(ledPin);
DachisXbee xbee(xbeeRx, xbeeTx);

void setup() {
  xbee.setup();

  led.blinkSlow();
  Serial.begin(9600);
  delay(1000);
  Serial.println("Connecting...");

  if (client.connect(server, 4454)) {
    Serial.println("Connected");
    client.println("GET /api/echo?what=arduino HTTP/1.0");
    client.println();
  }
  else {
    Serial.println("Connection failed");
  }

}

void loop() {

  char* code;
  if (code = xbee.receiveMessage()) {
    Serial.println("Got code!");
    Serial.println(code);
  }
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("Disconnecting");
    client.stop();
    for(;;)
      ;
  }

}

