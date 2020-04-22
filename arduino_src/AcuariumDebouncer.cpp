#include "AcuariumDebouncer.h"

InputDebouncer *AcuariumDebouncer::manualDebouncer = NULL;
InputDebouncer *AcuariumDebouncer::reservedDebouncer = NULL;
InputDebouncer *AcuariumDebouncer::whiteDebouncer = NULL;
InputDebouncer *AcuariumDebouncer::blueDebouncer = NULL;

/** 
  *  Configures the debouncers used by this static class
  *  
   */
static void AcuariumDebouncer::setupDebouncers(InputDebouncer *manualDebouncer, InputDebouncer *reservedDebouncer, InputDebouncer *whiteDebouncer, InputDebouncer *blueDebouncer)
{
  AcuariumDebouncer::manualDebouncer = manualDebouncer;
  AcuariumDebouncer::reservedDebouncer = reservedDebouncer;
  AcuariumDebouncer::whiteDebouncer = whiteDebouncer;
  AcuariumDebouncer::blueDebouncer = blueDebouncer;
}
    
/** 
  *  Debounces the manual input handling a change on it
  *  
   */
static void AcuariumDebouncer::handleChangeInInputManual()
{
  AcuariumDebouncer::manualDebouncer->processInputChange();
}

/** 
  *  Debounces the screen on off input handling a change on it
  *  
   */
static void AcuariumDebouncer::handleChangeInInputReserved()
{
  AcuariumDebouncer::reservedDebouncer->processInputChange();
}

/** 
  *  Debounces the white input handling a change on it
  *  
   */
static void AcuariumDebouncer::handleChangeInInputWhite()
{
  AcuariumDebouncer::whiteDebouncer->processInputChange();
}

/** 
  *  Debounces the blue input handling a change on it
  *  
   */
static void AcuariumDebouncer::handleChangeInInputBlue()
{
  AcuariumDebouncer::blueDebouncer->processInputChange();
}