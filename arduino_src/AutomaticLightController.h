#ifndef AutomaticLightController_h
#define AutomaticLightController_h

#include <RTClib.h>

class AutomaticLightController
{
    private:
      RTC_DS3231 *internalClock;
      
    public:
      /** 
        *  Finds the right light intensity based on the
        *  time get from the RTC passed as parameter
        */
      AutomaticLightController(RTC_DS3231 *internalClock);
      
      /** 
        *  Gets the current blue intensity
        *  
        */
      int calculateCurrentBlueLevel();

      /** 
        *  Gets the current white intensity
        *  
        */
      int calculateCurrentWhiteLevel();
};

#endif