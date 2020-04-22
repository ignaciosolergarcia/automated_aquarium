#include "IOManager.h"

/**
     Creates a new IOManager using the debouncers passed as
     parameter to control its inputs

*/
IOManager::IOManager(InputDebouncer *manualDebouncer, InputDebouncer *reservedDebouncer, InputDebouncer *whiteDebouncer, InputDebouncer *blueDebouncer)
{
  this->manualDebouncer = manualDebouncer;
  this->reservedDebouncer = reservedDebouncer;
  this->whiteDebouncer = whiteDebouncer;
  this->blueDebouncer = blueDebouncer;
}

/**
     Initializes the inputs and outputs of the Arduino
*/
void IOManager::setupInputOutputs()
{
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(inputManual, INPUT);
  pinMode(inputReserved, INPUT);
  pinMode(inputWhite, INPUT);
  pinMode(inputBlue, INPUT);
  pinMode(outputLedWhite1, OUTPUT);
  pinMode(outputLedWhite2, OUTPUT);
  pinMode(outputLedWhite3, OUTPUT);
  pinMode(outputLedWhite4, OUTPUT);
  pinMode(outputLedBlue1, OUTPUT);
  pinMode(outputLedBlue2, OUTPUT);
  pinMode(outputControlWhite, OUTPUT);
  pinMode(outputControlBlue, OUTPUT);
}

/**
     Initializes the interrupts (pin change based) of the Arduino
*/
void IOManager::setupInterrupts()
{
  attachPinChangeInterrupt(digitalPinToPCINT(inputManual), AcuariumDebouncer::handleChangeInInputManual, RISING);
  attachPinChangeInterrupt(digitalPinToPCINT(inputReserved), AcuariumDebouncer::handleChangeInInputReserved, RISING);
  attachPinChangeInterrupt(digitalPinToPCINT(inputWhite), AcuariumDebouncer::handleChangeInInputWhite, RISING);
  attachPinChangeInterrupt(digitalPinToPCINT(inputBlue), AcuariumDebouncer::handleChangeInInputBlue, RISING);
}

/**
  *  Returns true if the manual mode input is pressed
  *
  */
bool IOManager::isManualInputOn()
{
  return this->manualDebouncer->getInputState();
}

/**
  *  Returns true if the reserved input is pressed
  *
  */
bool IOManager::isReservedOn()
{
  return this->reservedDebouncer->getInputState();
}

/**
    Returns true if there is a pending request to activate
    the white lights
*/
bool IOManager::isWhiteOn()
{
  bool isWhiteOnNow = this->whiteDebouncer->getInputState();

  if (isWhiteOnNow != this->wasPreviousWhiteOn)
  {
    this->wasPreviousWhiteOn = isWhiteOnNow;
    return true;
  }
  else
  {
    return false;
  }
}

/**
    Returns true if there is a pending request to activate
    the blue lights
*/
bool IOManager::isBlueOn()
{
  bool isBlueOnNow = this->blueDebouncer->getInputState();

  if (isBlueOnNow != this->wasPreviousBlueOn)
  {
    this->wasPreviousBlueOn = isBlueOnNow;
    return true;
  }
  else
  {
    return false;
  }
}

/** 
  *  Sets the desired white led power and sets the status leds
  *  accordingly to the power
  *   
   */
void IOManager::setWhiteLevel(int level, bool activateIndicatorLeds)
{
  Serial.print("W: ");
  Serial.print(level);
  
  if (level >= 0 && level < 64 && activateIndicatorLeds)
  {
    this->writeWhiteLevel(LOW, LOW, LOW, LOW);
  }
  else if (level >= 64 && level < 128 && activateIndicatorLeds)
  {
    this->writeWhiteLevel(LOW, LOW, LOW, HIGH);
  }
  else if (level >= 128 && level < 192 && activateIndicatorLeds)
  {
    this->writeWhiteLevel(LOW, LOW, HIGH, HIGH);
  }
  else if (level >= 192 && level < 254 && activateIndicatorLeds)
  {
    this->writeWhiteLevel(LOW, HIGH, HIGH, HIGH);
  }
  else
  {
    this->writeWhiteLevel(HIGH, HIGH, HIGH, HIGH);
  }

  analogWrite(outputControlWhite, level);
}

/** 
  *  Sets the desired blue led power and sets the status leds
  *  accordingly to the power
  *  
   */
void IOManager::setBlueLevel(int level, bool activateIndicatorLeds)
{
  Serial.print(" B: ");
  Serial.println(level);
  
  if (level == 0 && activateIndicatorLeds)
  {
    this->writeBlueLevel(LOW, LOW);
  }
  else if (level >= 1 && level < 128 && activateIndicatorLeds)
  {
    this->writeBlueLevel(LOW, HIGH);
  }
  else
  {
    this->writeBlueLevel(HIGH, HIGH);
  }

  analogWrite(outputControlBlue, level);

}

void IOManager::writeBlueLevel(int blue1, int blue2)
{
  digitalWrite(outputLedBlue1, blue1);
  digitalWrite(outputLedBlue2, blue2);
}

void IOManager::writeWhiteLevel(int white1, int white2, int white3, int white4)
{
  digitalWrite(outputLedWhite1, white1);
  digitalWrite(outputLedWhite2, white2);
  digitalWrite(outputLedWhite3, white3);
  digitalWrite(outputLedWhite4, white4);
}