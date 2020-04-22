#include "InputDebouncer.h"

  /** 
    *  Sets up the serial communication and blocks the call
    *  until it is ready to communicate
     */
void InputDebouncer::processInputChange()
{
  long currentMillis = millis();
  if (currentMillis - this->startPushTime > this->debouncingTimeInMillis)
  {
    this->inputState = !this->inputState;
    this->startPushTime = currentMillis;
  }
}

/** 
  *  Gets the status of the input after debouncing it
  *  
   */
bool InputDebouncer::getInputState()
{
  return this->inputState;
}