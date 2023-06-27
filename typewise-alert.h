#pragma once

typedef enum
{
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

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

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CcoolingType &coolingType, double temperatureInC);

typedef enum
{
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct
{
  CcoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
