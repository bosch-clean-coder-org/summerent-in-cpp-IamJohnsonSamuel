#pragma once

typedef enum
{
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

class CcoolingType
{
public:
  virtual int getLowerLimit();
  virtual int getUpperLimit();
};

class PassiveCooling : public CcoolingType
{
public:
  int getLowerLimit()
  {
    return 0;
  }
  int getUpperLimit()
  {
    return 35;
  }
};

class MediumActiveCooling : public CcoolingType
{
public:
  int getLowerLimit()
  {
    return 0;
  }
  int getUpperLimit()
  {
    return 40;
  }
};

class HiActiveCooling : public CcoolingType
{
public:
  int getLowerLimit()
  {
    return 0;
  }
  int getUpperLimit()
  {
    return 45;
  }
};

typedef enum
{
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
  CcoolingType &coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
