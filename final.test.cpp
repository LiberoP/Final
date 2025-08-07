// qui solo TESTs

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "final.hpp"

#include "doctest.h"

TEST_CASE("Testing Simulation")
{
  fn::Simulation sim;
  fn::Pars parsA{1., 3., 2., 5., 10, 0.001, 4};
  fn::Pars parsB{1., 3., 2., 5., 10, 0.001, -1};
  fn::Pars parsC{1., 3.,    2., 5.,
                 10, 0.001, 10}; // A, B, C, D, N, delta-t, nstep
  fn::Point p1{20, 10};          // x0, y0
  fn::Point p2{10, 20};
  fn::Point p3(10, 10);

  REQUIRE(reg.size() == 0);

  SUBCASE("no parameters")
  {
    sim.addPoint(p1);
    CHECK_THROWS(sim.addPars());
  }

  SUBCASE("negative parameter")
  {
    sim.addPoint(p1);
    sim.addPars(-1., 3., 2.4, 4., 3, 0.001, 1);
    CHECK_THROWS(sim.addPars());
  }

  SUBCASE("null parameter")
  {
    sim.addPoint(p1);
    sim.addPars(1, 3.2, 0, 3, 3, 0.001, 1);
    CHECK_THROWS(sim.addPars());
  }

  SUBCASE("too low nth step value")
  {
    sim.addPars(parsB);
    // NB first step is i = 0
    CHECK_THROWS(sim.addPars());
  }

  SUBCASE("too high nth step value")
  {
    sim.addPars(parsC);
    sim.addPoint(p1); // NB 1000th step is i = 999
    CHECK_THROWS(sim.addPars());
  }

  SUBCASE("no starting point")
  {
    sim.addPars(parsA);
    CHECK_THROWS(sim.addPoint());
  }

  SUBCASE("negative starting point")
  {
    sim.addPars(parsA);
    sim.addPoint(2, -1);
    CHECK_THROWS(sim.addPoint());
  }

  SUBCASE("evolve 1")
  {
    sim.addPars(parsA);
    sim.addPoint(p1);
    auto result = sim.final();
    CHECK(result.x == doctest::Approx(16.64));
    CHECK(result.y == doctest::Approx(4.22));
    CHECK(result.H == doctest::Approx(30.442));
  }

  SUBCASE("evolve 2")
  {
    sim.addPars(parsA);
    sim.addPoint(p2);
    auto result = sim.final();
    CHECK(result.x == doctest::Approx());
    CHECK(result.y == doctest::Approx());
    CHECK(result.H == doctest::Approx());
  }

  SUBCASE("evolve 3")
  {
    sim.addPars(parsA);
    sim.addPoint(p3);
    auto result = sim.final();
    CHECK(result.x == doctest::Approx()); // calcolare analiticamente!
    CHECK(result.y == doctest::Approx());
    CHECK(result.H == doctest::Approx());
  }

  SUBCASE("check Nth step values in case 1")
  {
    sim.addPars(parsA);
    sim.addPoint(p1);
    sim.nstep(48);
    CHECK(nstep.x == doctest::Approx()); // calcolare analiticamente!
    CHECK(nstep.y == doctest::Approx());
    CHECK(nstep.H == doctest::Approx());
  }

  SUBCASE("check Nth step values in case 2")
  {
    sim.addPars(parsA);
    sim.addPoint(p2);
    sim.nstep(717);
    CHECK(nstep.x == doctest::Approx()); // calcolare analiticamente!
    CHECK(nstep.y == doctest::Approx());
    CHECK(nstep.H == doctest::Approx());
  }

  SUBCASE("check Nth step values in case 3")
  {
    sim.addPars(parsA);
    sim.addPoint(p3);
    sim.nstep(82);
    CHECK(nstep.x == doctest::Approx()); // calcolare analiticamente!
    CHECK(nstep.y == doctest::Approx());
    CHECK(nstep.H == doctest::Approx());
  }
}
