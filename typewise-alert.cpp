#include "typewise-alert.h"
#include "iostream"

CbreachType *inferBreach(double value, double lowerLimit, double upperLimit)
{
  CbreachType *breachType;
  if (value < lowerLimit)
  {
    breachType = new BreachTypeTooLow;
    std::cout << "BreachTypeTooLow: " << breachType->value << std::endl;
    return breachType;
  }
  if (value > upperLimit)
  {
    std::cout << "BreachTypeTooHigh" << std::endl;
    return new BreachTypeTooHigh;
  }
  std::cout << "BreachTypeNormal" << std::endl;
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
