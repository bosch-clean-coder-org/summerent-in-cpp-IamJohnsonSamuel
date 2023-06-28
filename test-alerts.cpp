#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits")
{
  CbreachType *breachType = inferBreach(12, 20, 30);
  std::cout << "output:" << breachType->getBreachType() << std::endl;
  REQUIRE(breachType->getBreachType() == TOO_LOW);
}

TEST_CASE("infers the breach according to limits high")
{
  CbreachType *breachType = inferBreach(40, 20, 30);
  std::cout << "output:" << breachType->getBreachType() << std::endl;
  REQUIRE(breachType->getBreachType() == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits normal")
{
  CbreachType *breachType = inferBreach(25, 20, 30);
  std::cout << "output:" << breachType->getBreachType() << std::endl;
  REQUIRE(breachType->getBreachType() == NORMAL);
}

TEST_CASE("send to Controller")
{
  CbreachType *breachType = new BreachTypeTooHigh();
  sendToController(*breachType);
}

TEST_CASE("send to email High")
{
  CbreachType *breachType = new BreachTypeTooHigh();
  breachType->sendToEmail();
}

TEST_CASE("send to email low")
{
  CbreachType *breachType = new BreachTypeTooLow();
  breachType->sendToEmail();
}

TEST_CASE("send to email Normal")
{
  CbreachType *breachType = new BreachTypeNormal();
  breachType->sendToEmail();
}

TEST_CASE("classify temperature breach low")
{
  CbreachType *breachType = classifyTemperatureBreach(*(new PassiveCooling), -1);
  REQUIRE(breachType->getBreachType() == TOO_LOW);
}

TEST_CASE("classify temperature breach high")
{
  CbreachType *breachType = classifyTemperatureBreach(*(new PassiveCooling), 36);
  REQUIRE(breachType->getBreachType() == TOO_HIGH);
}

TEST_CASE("classify temperature breach Normal")
{
  CbreachType *breachType = classifyTemperatureBreach(*(new PassiveCooling), 30);
  REQUIRE(breachType->getBreachType() == NORMAL);
}