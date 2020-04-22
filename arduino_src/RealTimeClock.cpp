#include "RealTimeClock.h"

RealTimeClock::RealTimeClock(RTC_DS3231 *internalClock)
{
  this->internalClock = internalClock;
}
    
/** 
  *  Initializes the communication with the RTC and returns
  *  a value indicating success or not.
   */
bool RealTimeClock::setupRealTimeClock()
{
  return this->internalClock->begin();
}

