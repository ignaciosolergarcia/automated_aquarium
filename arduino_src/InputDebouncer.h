#ifndef InputDebouncer_h
#define InputDebouncer_h

#include <Arduino.h>

class InputDebouncer
{
  private:
    volatile bool inputState;
    long startPushTime;
    static const int debouncingTimeInMillis = 250;
    
  public:
    /** 
      *  Sets up the serial communication and blocks the call
      *  
       */
    void processInputChange();
    
    /** 
      *  Gets the status of the input after debouncing it
      *  
       */
    bool getInputState();
};

#endif