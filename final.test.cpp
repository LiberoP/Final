// qui solo TESTs

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "final.hpp"

#include "doctest.h"

TEST_CASE("Testing Simulation")
{
  fn::Simulation sim;
  fn::Pars parsA{1., 1., 1., 1., 0.001}; // A, B, C, D, delta-t
  fn::In p1{20, 10, 1000};               // x0, y0, N
  fn::In p2{10, 20, 1000};
  fn::In p3(10, 10, 100);
  // ...

  REQUIRE(); // COMPLETARE

  SUBCASE("no parameters")
  {
    sim.addIn(p1);
    CHECK_THROWS(sim.addPars());
  }

  SUBCASE("negative parameter")
  {
    sim.addIn(p1);
    sim.addPars(-1., 3., 2.4, 4., 0.001);
    CHECK_THROWS(sim.addPars());
  }

  SUBCASE("null parameter")
  {
    sim.addIn(p1);
    sim.addPars(1, 3.2, 0, 1, 0.001);
    CHECK_THROWS(sim.addPars());
  }

  SUBCASE("no starting point")
  {
    sim.addPars(parsA);
    CHECK_THROWS(sim.addIn());
  }

  SUBCASE("negative starting point")
  {
    sim.addPars(parsA);
    sim.addIn(2, -1, 100);
    CHECK_THROWS(sim.addIn());
  }

  SUBCASE("too low nth step value")
  {
    sim.addPars(parsA);
    sim.addIn(p1);
    sim.nstep(-1); // NB first step is i = 0
    CHECK_THROWS(sim.nstep());
  }

  SUBCASE("too high nth step value")
  {
    sim.addPars(parsA);
    sim.addIn(p1);
    sim.nstep(1000); // NB 1000th step is i = 999
    CHECK_THROWS(sim.nstep());
  }

  SUBCASE("evolve 1")
  {
    sim.addPars(parsA);
    sim.addIn(p1);
    auto result = sim.evolve();
    CHECK(result.x == doctest::Approx()); // calcolare analiticamente!
    CHECK(result.y == doctest::Approx());
    CHECK(result.H == doctest::Approx());
  }

  SUBCASE("evolve 2")
  {
    sim.addPars(parsA);
    sim.addIn(p2);
    auto result = sim.evolve();
    CHECK(result.x == doctest::Approx()); // calcolare analiticamente!
    CHECK(result.y == doctest::Approx());
    CHECK(result.H == doctest::Approx());
  }

  SUBCASE("evolve 3")
  {
    sim.addPars(parsA);
    sim.addIn(p3);
    auto result = sim.evolve();
    CHECK(result.x == doctest::Approx()); // calcolare analiticamente!
    CHECK(result.y == doctest::Approx());
    CHECK(result.H == doctest::Approx());
  }

  SUBCASE("check Nth step values in case 1")
  {
    sim.addPars(parsA);
    sim.addIn(p1);
    sim.nstep(48);
    CHECK(nstep.x == doctest::Approx()); // calcolare analiticamente!
    CHECK(nstep.y == doctest::Approx());
    CHECK(nstep.H == doctest::Approx());
  }

  SUBCASE("check Nth step values in case 2")
  {
    sim.addPars(parsA);
    sim.addIn(p2);
    sim.nstep(717);
    CHECK(nstep.x == doctest::Approx()); // calcolare analiticamente!
    CHECK(nstep.y == doctest::Approx());
    CHECK(nstep.H == doctest::Approx());
  }

  SUBCASE("check Nth step values in case 3")
  {
    sim.addPars(parsA);
    sim.addIn(p3);
    sim.nstep(82);
    CHECK(nstep.x == doctest::Approx()); // calcolare analiticamente!
    CHECK(nstep.y == doctest::Approx());
    CHECK(nstep.H == doctest::Approx());
  }
}
