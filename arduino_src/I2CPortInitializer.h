#ifndef I2CPortInitializer_h
#define I2CPortInitializer_h

#include <Wire.h>

class I2CPortInitializer
{
  public:
    /** 
      *  Configures the I2C bus so it can communicate with the display
      *  and the RTC with the right speed
       */
    void setupI2CAndSetSpeed();
};

#endif