#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit)
{
  if (value < lowerLimit)
  {
    return TOO_LOW;
  }
  if (value > upperLimit)
  {
    return TOO_HIGH;
  }
  return NORMAL;
}

class CcoolingType
{
  int getLowerLimit();
  int getUpperLimit();
}

class PassiveCooling extends CcoolingType
{
  int getLowerLimit()
  {
    return 0;
  }
  int getUpperLimit()
  {
    return 35;
  }
}

class MediumActiveCooling extends CcoolingType
{
  int getLowerLimit()
  {
    return 0;
  }
  int getUpperLimit()
  {
    return 40;
  }
}

class HiActiveCooling extends CcoolingType
{
  int getLowerLimit()
  {
    return 0;
  }
  int getUpperLimit()
  {
    return 45;
  }
}

BreachType
classifyTemperatureBreach(
    CcoolingType &coolingType, double temperatureInC)
{
  int lowerLimit = coolingType.getLowerLimit();
  int upperLimit = CoolingType.getUpperLimit();

  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{

  BreachType breachType = classifyTemperatureBreach(
      batteryChar.coolingType, temperatureInC);

  switch (alertTarget)
  {
  case TO_CONTROLLER:
    sendToController(breachType);
    break;
  case TO_EMAIL:
    sendToEmail(breachType);
    break;
  }
}

void sendToController(BreachType breachType)
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType)
{
  const char *recepient = "a.b@c.com";
  switch (breachType)
  {
  case TOO_LOW:
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
    break;
  case TOO_HIGH:
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
    break;
  case NORMAL:
    break;
  }
}
