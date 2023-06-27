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

class CbreachType
{
public:
  BreachType value;
  virtual void sendToEmail(const char *recepient);
};

class BreachTypeTooLow : public CbreachType
{
public:
  BreachType value;
  BreachTypeTooLow()
  {
    value = TOO_LOW;
  }
  virtual void sendToEmail(const char *recepient)
  {
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
  }
};

class BreachTypeTooHigh : public CbreachType
{
public:
  BreachType value;
  BreachTypeTooHigh()
  {
    value = TOO_HIGH;
  }
  virtual void sendToEmail(const char *recepient)
  {
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
  }
};

class BreachTypeNormal : public CbreachType
{
public:
  BreachType value;
  BreachTypeNormal()
  {
    value = NORMAL;
  }
  virtual void sendToEmail(const char *recepient)
  {
  }
};
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
