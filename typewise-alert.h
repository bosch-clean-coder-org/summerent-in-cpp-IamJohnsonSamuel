
#ifndef _TYPEWISE_H_
#define _TYPEWISE_H_

#include "iostream"
typedef enum
{
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

class CcoolingType
{
public:
  CcoolingType() {}
  virtual ~CcoolingType() {}
  virtual int getLowerLimit()
  {
    return 0;
  }
  virtual int getUpperLimit()
  {
    return 0;
  }
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
  CbreachType() {}
  virtual ~CbreachType(){};
  virtual void sendToEmail()
  {
    const char *recepient = "a.b@c.com";
    (void)recepient;
  }
  virtual BreachType getBreachType()
  {
    return value;
  }
};

class BreachTypeTooLow : public CbreachType
{
public:
  BreachType value;
  BreachTypeTooLow()
  {
    std::cout << "const BreachTypeTooLow" << std::endl;
    value = TOO_LOW;
  }
  virtual void sendToEmail()
  {
    const char *recepient = "a.b@c.com";
    std::cout << "To: " << recepient << std::endl;
    // printf("To: %s\n", recepient);
    std::cout << "Hi, the temperature is too low" << std::endl;
    // printf("Hi, the temperature is too low\n");
  }
  virtual BreachType getBreachType()
  {
    return value;
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
  virtual void sendToEmail()
  {
    const char *recepient = "a.b@c.com";
    std::cout << "To: " << recepient << std::endl;
    // printf("To: %s\n", recepient);
    std::cout << "Hi, the temperature is too high" << std::endl;
    // printf("Hi, the temperature is too high\n");
  }
  virtual BreachType getBreachType()
  {
    return value;
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
    (void)recepient;
  }
  virtual BreachType getBreachType()
  {
    return value;
  }
};
CbreachType *inferBreach(double value, double lowerLimit, double upperLimit);
CbreachType *classifyTemperatureBreach(CcoolingType &coolingType, double temperatureInC);

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

void sendToController(CbreachType &breachType);
void sendToEmail(BreachType breachType);

#endif /*_TYPEWISE_H_*/