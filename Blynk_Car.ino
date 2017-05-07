/*
 * Car logic for manual control using the Blynk service.
 */

#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>

#include "VirtualParser.h"

// All virtual pin updates from Blynk are sent here
VirtualParser parser;

char localAuth[] = "f7bbbf4d3f754bd1a09a4ae38a313487";

char ssid[] = "NETGEAR01";
char pass[] = "pitterpatter";

// Start the parser for Blynk virtual pin messages
BLYNK_WRITE_DEFAULT() {
  int pin = request.pin;
  int vParam = param[0].asInt();

  parser.vParse(pin, vParam);
}

void setup()
{ 
  Serial.begin(9600);
  
  // Connect to local server
  Blynk.begin(localAuth, ssid, pass, IPAddress(192,168,1,198));
}

void loop()
{
  Blynk.run();
}

