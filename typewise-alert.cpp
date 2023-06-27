#include "typewise-alert.h"

CbreachType *inferBreach(double value, double lowerLimit, double upperLimit)
{
  if (value < lowerLimit)
  {
    return new BreachTypeTooLow;
  }
  if (value > upperLimit)
  {
    return new BreachTypeTooHigh;
  }
  return new BreachTypeNormal;
}

CbreachType *classifyTemperatureBreach(
    CcoolingType &coolingType, double temperatureInC)
{
  int lowerLimit = coolingType.getLowerLimit();
  int upperLimit = coolingType.getUpperLimit();

  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{

  CbreachType *breachType;
  breachType = classifyTemperatureBreach(
      batteryChar.coolingType, temperatureInC);

  switch (alertTarget)
  {
  case TO_CONTROLLER:
    sendToController(*breachType);
    break;
  case TO_EMAIL:
    breachType->sendToEmail("a.b@c.com");
  }
  delete breachType;
}

void sendToController(CbreachType &breachType)
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType.value);
}

// void sendToEmail(BreachType breachType)
// {
//   const char *recepient = "a.b@c.com";
//   switch (breachType)
//   {
//   case TOO_LOW:
//     printf("To: %s\n", recepient);
//     printf("Hi, the temperature is too low\n");
//     break;
//   case TOO_HIGH:
//     printf("To: %s\n", recepient);
//     printf("Hi, the temperature is too high\n");
//     break;
//   case NORMAL:
//     break;
//   }
// }
