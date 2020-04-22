#ifndef RealTimeClock_h
#define RealTimeClock_h

#include <RTClib.h>

class RealTimeClock
{
  private:
    RTC_DS3231 *internalClock;
    
  public:
    RealTimeClock(RTC_DS3231 *internalClock);
  
    /** 
      *  Initializes the communication with the RTC and returns
      *  a value indicating success or not.
       */
    bool setupRealTimeClock();
    
    /** 
      *  Initializes the time of the RTC if there is no backup
      *  avaliable.
       */
    bool initializeRealTimeClockTimeToBuildTimeIfNoDataAvailable();
};

#endif