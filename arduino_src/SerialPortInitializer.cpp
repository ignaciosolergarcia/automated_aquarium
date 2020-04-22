#include "SerialPortInitializer.h"

/** 
  *  Sets up the serial communication and blocks the call
  *  until it is ready to communicate
   */
void SerialPortInitializer::setupSerialAndWaitForConsoleReady()
{
  Serial.begin(9600);
  while (!Serial);; // Wait until console ready
}