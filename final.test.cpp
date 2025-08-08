// qui solo TESTs

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "final.hpp"

#include "doctest.h"

TEST_CASE("Testing Simulation")
{
  fn::Simulation sim;
  fn::Pars parsA{1., 3., 2., 5., 10, 0.001, 4}; // A, B, C, D, N, delta-t, nstep
  fn::Point p1{20., 10.};                       // x0, y0
  fn::Point p2{10., 20.};
  fn::Point p3{10., 10.};

  REQUIRE(sim.size() == 0);

  // SUBCASE("no parameters") // to implement in .cpp?
  //{
  //   sim.addPoint(p1);
  //   CHECK_THROWS(sim.addPars());
  // }

  // SUBCASE("negative parameter")
  //{
  //   sim.addPoint(p1);

  //  CHECK_THROWS(sim.addPars({-1., 3., 2.4, 4., 3, 0.001, 1}));
  //}

  SUBCASE("null parameter") 
 {
    sim.addPoint(p1);
 
    CHECK_THROWS(sim.addPars({1., 3.2, 0, 3., 3, 0.001, 1}));
  }

  // SUBCASE("too low nth step value")
  // {
  //
  //   // NB first step is i = 0
  //   CHECK_THROWS(sim.addPars({1., 3., 2., 5., 10, 0.001, -1}));
  // }

  SUBCASE("too high nth step value") //
  
 {
    sim.addPoint(p1);
    // NB 1000th step is i = 999
    CHECK_THROWS(sim.addPars({1., 3., 2., 5., 10, 0.001, 10}));
  }

  // SUBCASE("no starting point")
  // {
  //   sim.addPars(parsA);
  //   CHECK_THROWS(sim.addPoint());
  // }

  //  SUBCASE("negative starting point")
  //  {
  //    sim.addPars(parsA);
  //    sim.addPoint({2, -1});
  //    CHECK_THROWS(sim.addPoint());
  //  }

  SUBCASE("final 1")
  {
    sim.addPars(parsA);
    sim.addPoint(p1);
    auto result = sim.final();
    CHECK(result.x == doctest::Approx(17.66));
    CHECK(result.y == doctest::Approx(11.40));
    CHECK(result.H == doctest::Approx(52.72));
  }

  SUBCASE("final 2")
  {
    sim.addPars(parsA);
    sim.addPoint(p2);
    auto result = sim.final();
    CHECK(result.x == doctest::Approx(5.35));
    CHECK(result.y == doctest::Approx(22.09));
    CHECK(result.H == doctest::Approx(65.49));
  }

  SUBCASE("final 3")
  {
    sim.addPars(parsA);
    sim.addPoint(p3);
    auto result = sim.final();
    CHECK(result.x == doctest::Approx(7.33));
    CHECK(result.y == doctest::Approx(11.30));
    CHECK(result.H == doctest::Approx(36.18));
  }

  SUBCASE("check Nth step values in case 1")
  {
    sim.addPars(parsA);
    sim.addPoint(p1);
    auto nstep = sim.nstep();
    CHECK(nstep.x == doctest::Approx(14.21));
    CHECK(nstep.y == doctest::Approx(13.39));
    CHECK(nstep.H == doctest::Approx(52.72));
  }

  SUBCASE("check Nth step values in case 2")
  {
    sim.addPars(parsA);
    sim.addPoint(p2);
    auto nstep = sim.nstep();
    CHECK(nstep.x == doctest::Approx(7.85));
    CHECK(nstep.y == doctest::Approx(21.05));
    CHECK(nstep.H == doctest::Approx(65.49));
  }

  SUBCASE("check Nth step values in case 3")
  {
    sim.addPars(parsA);
    sim.addPoint(p3);
    auto nstep = sim.nstep();
    CHECK(nstep.x == doctest::Approx(8.87));
    CHECK(nstep.y == doctest::Approx(10.57));
    CHECK(nstep.H == doctest::Approx(36.18));
  }
}
