#include "I2CPortInitializer.h"

/** 
  *  Configures the I2C bus so it can communicate with the display
  *  and the RTC with the right speed
   */
void I2CPortInitializer::setupI2CAndSetSpeed()
{
  Wire.begin();
  Wire.setClock(400000L);
}

