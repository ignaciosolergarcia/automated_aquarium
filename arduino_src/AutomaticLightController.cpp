#include "AutomaticLightController.h"

/** 
  *  Finds the right light intensity based on the
  *  time get from the RTC passed as parameter
  */
AutomaticLightController::AutomaticLightController(RTC_DS3231 *internalClock)
{
  this->internalClock = internalClock;
}

/** 
  *  Gets the current blue intensity
  *  
  */
int AutomaticLightController::calculateCurrentBlueLevel()
{
  int result;
  DateTime nowDate = this->internalClock->now();
  TimeSpan nowTime (0, nowDate.hour(), nowDate.minute(), nowDate.second());

  if (nowTime.hours() >= 0 && nowTime.hours() < 17)
  {
    result = 255;
  }
  else if (nowTime.hours() >= 17 && nowTime.hours() < 19)
  {
    TimeSpan top (0, 19, 0, 0);
    TimeSpan untilTop = top - nowTime;
    int minutesRemaining = untilTop.totalseconds() / 60;
    
    result = (minutesRemaining * 2.11);
  }
  else if (nowTime.hours() >= 19 && nowTime.hours() < 22)
  {
    result = 0;
  }
  else
  {
    TimeSpan top (0, 23, 59, 59);
    TimeSpan untilTop = top - nowTime;
    int minutesRemaining = untilTop.totalseconds() / 60;

    result = (minutesRemaining * -2.11) + 255.0;
  }
  
  return result;
}

/** 
  *  Gets the current white intensity
  *  
  */
int AutomaticLightController::calculateCurrentWhiteLevel()
{
  int result;
  
  DateTime nowDate = this->internalClock->now();
  TimeSpan nowTime (0, nowDate.hour(), nowDate.minute(), nowDate.second());

  Serial.print(nowDate.hour());
  Serial.print(":");
  Serial.print(nowDate.minute());
  Serial.print(":");
  Serial.println(nowDate.second());
        
  if (nowTime.hours() >= 0 && nowTime.hours() < 8)
  {
    result = 254;
  }
  else if (nowTime.hours() >= 8 && nowTime.hours() < 14)
  {
    TimeSpan top (0, 14, 0, 0);
    TimeSpan untilTop = top - nowTime;
    int minutesRemaining = untilTop.totalseconds() / 60;
    
    // 0.7*x
    result = max(min((0.7 * minutesRemaining), 254.0), 0.0);
  }
  else if (nowTime.hours() >= 14 && nowTime.hours() < 20)
  {
    TimeSpan top (0, 20, 0, 0);
    TimeSpan untilTop = top - nowTime;
    int minutesRemaining = untilTop.totalseconds() / 60;
    
    // -0.7*x+255
    result = max(min((-0.7 * minutesRemaining + 255.0), 254.0), 0.0);
  }
  else
  {
    result = 254;
  }

  return result;
}