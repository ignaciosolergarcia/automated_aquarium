#ifndef AcuariumDebouncer_h
#define AcuariumDebouncer_h

#include "InputDebouncer.h"

class AcuariumDebouncer
{
  private:
    static InputDebouncer *manualDebouncer;
    static InputDebouncer *reservedDebouncer;
    static InputDebouncer *whiteDebouncer;
    static InputDebouncer *blueDebouncer;
    
  public:
    /** 
      *  Configures the debouncers used by this static class
      *  
       */
    static void setupDebouncers(InputDebouncer *manualDebouncer, InputDebouncer *reservedDebouncer, InputDebouncer *whiteDebouncer, InputDebouncer *blueDebouncer);
    
    /** 
      *  Debounces the manual input handling a change on it
      *  
       */
    static void handleChangeInInputManual();
    
    /** 
      *  Debounces the reserved input handling a change on it
      *  
       */
    static void handleChangeInInputReserved();
    
    /** 
      *  Debounces the white input handling a change on it
      *  
       */
    static void handleChangeInInputWhite();
    
    /** 
      *  Debounces the blue input handling a change on it
      *  
       */
    static void handleChangeInInputBlue();
};

#endif