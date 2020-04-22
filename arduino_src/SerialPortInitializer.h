#ifndef SerialPortInitializer_h
#define SerialPortInitializer_h

#include <Arduino.h>

class SerialPortInitializer
{
  public:
    /** 
      *  Sets up the serial communication and blocks the call
      *  until it is ready to communicate
       */
  void setupSerialAndWaitForConsoleReady();
};

#endif