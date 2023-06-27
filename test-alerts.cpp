#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits")
{
  CbreachType *breachType = inferBreach(12, 20, 30);
  REQUIRE(breachType->value == TOO_LOW);
}
