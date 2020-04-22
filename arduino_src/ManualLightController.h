#ifndef ManualLightController_h
#define ManualLightController_h

#include "IOManager.h"

class ManualLightController
{
    private:
      IOManager *ioManager;
      bool isRisingBlue = true;
      bool isRisingWhite = true;
      int currentBlueLevel = 0;
      int currentWhiteLevel = 0;
      
    public:
      /** 
        *  Builds a new object in charge of managing the lights in manual mode
        *  
        */
      ManualLightController(IOManager *ioManager);
      
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
      
      void setLevels(int white, int blue);
};

#endif