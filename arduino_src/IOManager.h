#ifndef IOManager_h
#define IOManager_h

#include <Arduino.h>
#include <PinChangeInterrupt.h>
#include <PinChangeInterruptBoards.h>
#include <PinChangeInterruptPins.h>
#include <PinChangeInterruptSettings.h>

#include "AcuariumDebouncer.h"
#include "InputDebouncer.h"

class IOManager
{
  private:
    static const int inputManual = 3;
    static const int inputReserved = 2;
    static const int inputWhite = 5;
    static const int inputBlue = 4;

    static const int outputLedWhite1 = 14;
    static const int outputLedWhite2 = 7;
    static const int outputLedWhite3 = 8;
    static const int outputLedWhite4 = 9;
    static const int outputLedBlue1 = 6;
    static const int outputLedBlue2 = 12;
    static const int outputControlWhite = 10;
    static const int outputControlBlue = 11;

    InputDebouncer *manualDebouncer;
    InputDebouncer *reservedDebouncer;
    InputDebouncer *whiteDebouncer;
    InputDebouncer *blueDebouncer;
    
        bool wasPreviousWhiteOn;
    bool wasPreviousBlueOn;
    
    void writeBlueLevel(int blue1, int blue2);
    void writeWhiteLevel(int white1, int white2, int white3, int white4);
    
  public:
    /** 
      *  Creates a new IOManager using the debouncers passed as
      *  parameter to control its inputs
      *  
       */
    IOManager(InputDebouncer *manualDebouncer, InputDebouncer *reservedDebouncer, InputDebouncer *whiteDebouncer, InputDebouncer *blueDebouncer);
    
    /**
      *   Initializes the inputs and outputs of the Arduino
      */
    void setupInputOutputs();

    /**
      *   Initializes the interrupts (pin change based) of the Arduino
      */
    void setupInterrupts();
    
    /** 
      *  Returns true if the manual mode input is pressed
      *  
       */
    bool isManualInputOn();
    
    /** 
      *  Returns true if the reserved input is pressed
      *  
       */
    bool isReservedOn();
    
    /** 
      *  Returns true if the white input is  activated
      *  
       */
    bool isWhiteOn();
    
    /** 
      *  Returns true if the blue input is  activated
      *  
       */
    bool isBlueOn();

    /** 
      *  Sets the desired white led power and sets the status leds
      *  accordingly to the power
      *   
       */
    void setWhiteLevel(int level, bool activateIndicatorLeds);

    /** 
      *  Sets the desired blue led power and sets the status leds
      *  accordingly to the power
      *  
       */
    void setBlueLevel(int level, bool activateStatusLeds);
};

#endif