#include "ManualLightController.h"

/** 
  *  Builds a new object in charge of managing the lights in manual mode
  *  
  */
ManualLightController::ManualLightController(IOManager *ioManager)
{
  this->ioManager = ioManager;
}

/**
  *  Gets the current white intensity
  *
  */
int ManualLightController::calculateCurrentBlueLevel()
{
  Serial.print("Man blue: ");
//  Serial.print("ON: ");
//  Serial.print(this->ioManager->isBlueOn());
//  Serial.print(" - Rising: ");
//  Serial.print(isRisingBlue);
//  Serial.print(" - Level: ");
  Serial.println(currentBlueLevel);
  
  if (this->ioManager->isBlueOn())
  {
    if (this->currentBlueLevel == 128 && !this->isRisingBlue)
    {
      this->currentBlueLevel = 0;
    }
    else if(this->currentBlueLevel == 128 && this->isRisingBlue)
    {
      this->currentBlueLevel = 255;      
    }
    else
    {
      this->currentBlueLevel = 128;
    }
  }
  
  if (this->currentBlueLevel == 0)
  {
    this->isRisingBlue = true;
  }
  else if (this->currentBlueLevel == 255)
  {
    this->isRisingBlue = false;
  }
  
  return this->currentBlueLevel;
}

/**
  *  Gets the current white intensity
  *
  */
int ManualLightController::calculateCurrentWhiteLevel()
{
  Serial.print("Man white: ");
//  Serial.print("ON: ");
//  Serial.print(this->ioManager->isWhiteOn());
//  Serial.print(" - Rising: ");
//  Serial.print(isRisingWhite);
//  Serial.print(" - Level: ");
  Serial.println(currentWhiteLevel);
  
  if (this->ioManager->isWhiteOn())
  {
    if (this->currentWhiteLevel == 64 && !this->isRisingWhite)
    {
      this->currentWhiteLevel = 0;  
    }
    else if ((this->currentWhiteLevel == 0 && this->isRisingWhite) || (this->currentWhiteLevel == 128 && !this->isRisingWhite))
    {
      this->currentWhiteLevel = 64;      
    }
    else if ((this->currentWhiteLevel == 64 && this->isRisingWhite) || (this->currentWhiteLevel == 192 && !this->isRisingWhite))
    {
      this->currentWhiteLevel = 128;      
    }
    else if ((this->currentWhiteLevel == 128 && this->isRisingWhite) || (this->currentWhiteLevel == 255 && !this->isRisingWhite))
    {
      this->currentWhiteLevel = 192;      
    }
    else if (this->currentWhiteLevel == 255 && !this->isRisingWhite)
    {
      this->currentWhiteLevel = 0;  
    }
  }
  
  if (this->currentWhiteLevel == 0)
  {
    this->isRisingWhite = true;
  }
  else if (this->currentWhiteLevel == 255)
  {
    this->isRisingWhite = false;
  }
  
  return this->currentWhiteLevel;
}

void ManualLightController::setLevels(int white, int blue)
{
  if (white >= 0 && white < 32)
  {
    this->currentWhiteLevel = 0;
  }
  else if (white >= 32 && white < 96)
  {
    this->currentWhiteLevel = 64;    
  }
  else if (white >= 96 && white < 160)
  {
    this->currentWhiteLevel = 128;    
  }
  else if (white >= 160 && white < 224)
  {
    this->currentWhiteLevel = 192;    
  }
  else
  {
    this->currentWhiteLevel = 255;  
  }

 if (blue >= 0 && blue < 64)
  {
    this->currentBlueLevel = 0;
  }
  else if (blue >= 64 && blue < 192)
  {
    this->currentBlueLevel = 128;    
  }
  else
  {
    this->currentBlueLevel = 255;    
  }
}