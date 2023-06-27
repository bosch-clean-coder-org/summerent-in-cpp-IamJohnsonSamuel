#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits")
{
  CbreachType *breachType = new BreachTypeTooLow;
  std::cout << "output:" << breachType->getBreachType() << std::endl;
  REQUIRE(breachType->getBreachType() == TOO_LOW);
}
