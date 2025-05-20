// qui solo TESTs

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "final.hpp"

#include "doctest.h"

TEST_CASE("...")
{
  // ...

  REQUIRE(); // ...

  SUBCASE("abc")
  {
    CHECK_THROWS(reg.fit());
  } // ...
  }
