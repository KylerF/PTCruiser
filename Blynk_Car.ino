/*
 * Car logic for manual control using the Blynk service.
 */
#define BLYNK_PRINT Serial

#include <Thread.h>
#include <ThreadController.h>

#include <SPI.h>
#include <WiFi101.h>
#include <WiFi101OTA.h>
#include<Wire.h>
#include <BlynkSimpleMKR1000.h>

#include "VirtualParser.h"

// All virtual pin updates from Blynk are sent here
VirtualParser parser;

// Local server parameters
char localAuth[] = "efdfa96a36d34af7aaa1f14792c79fd6";
IPAddress server = IPAddress(10,0,0,6);
int port = 8442;

// WiFi network parameters
char ssid[] = "ROUTER RICK";
char pass[] = "pitterpatter";

// Set up thread control for subsystems
ThreadController controller = ThreadController();
Thread sonarThread = Thread();

// Start the parser for Blynk virtual pin messages
BLYNK_WRITE_DEFAULT() {
  int pin = request.pin;
  int vParam = param[0].asInt();

  parser.vParse(pin, vParam);
}

// Functions to call scheduled operations
void runSonar() {
  parser.checkSensors();
}

void setup()
{ 
  Serial.begin(9600);
  
  // Connect to local server
  Blynk.begin(localAuth, ssid, pass, server, port);

  // Set up threaded execution
  sonarThread.onRun(runSonar);
  sonarThread.setInterval(50);
  controller.add(&sonarThread);

  // Set up WIFI port for OTA sketch uploads
  WiFiOTA.begin("PTCruiser", "zoomzoom", InternalStorage);
}

void loop()
{
  // Check for OTA updates
  WiFiOTA.poll();
  
  // Run Blynk connetion and threaded execution timer
  Blynk.run();
  controller.run();
}

