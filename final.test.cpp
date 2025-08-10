// qui solo TESTs

// aggiungere altri test!

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "final.hpp"

#include "doctest.h"

TEST_CASE("Testing Simulation")
{
  fn::Simulation sim;
  fn::Pars parsA{1., 3., 2., 5., 10, 0.001, 4}; // A, B, C, D, N, delta-t, nstep
  fn::Pars pars0{1., 3.2, 0, 3., 3, 0.001, 1};
  fn::Pars parshigh{1., 3.2, 1., 3., 3, 0.001, 11};
  fn::Point p1{20., 10.}; // x0, y0
  fn::Point p2{10., 20.};
  fn::Point p3{10., 10.};

  REQUIRE(sim.size() == 0);

  // ============ADDITIONAL TESTS (l'utente inserisce ad es. nessun===========
  // ============parametro, o un N non intero) to implement in================
  // ============ .cpp?:=====================================================

  // SUBCASE("no parameters")
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
    CHECK_THROWS_AS(sim.addPars(pars0), std::runtime_error);
  }

  // SUBCASE("too low nth step value")
  // {
  //
  //   // NB first step is i = 0
  //   CHECK_THROWS(sim.addPars({1., 3., 2., 5., 10, 0.001, -1}));
  // }

  SUBCASE("too high nth step value") //

  {
    // NB 1000th step is i = 999
    CHECK_THROWS_AS(sim.addPars(parshigh), std::runtime_error);
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
    sim.addPoint(p1, parsA);
    sim.evolve(parsA, p1);
    auto result = sim.final();
    CHECK(result.x == doctest::Approx(14.21).epsilon(0.05));
    CHECK(result.y == doctest::Approx(13.39).epsilon(0.05));
    CHECK(result.H == doctest::Approx(52.72).epsilon(0.05));
  }

  SUBCASE("final 2")
  {
    sim.addPars(parsA);
    sim.addPoint(p2, parsA);
    sim.evolve(parsA, p1);
    auto result = sim.final();
    CHECK(result.x == doctest::Approx(5.35).epsilon(0.05));
    CHECK(result.y == doctest::Approx(22.09).epsilon(0.05));
    CHECK(result.H == doctest::Approx(65.49).epsilon(0.05));
  }

  SUBCASE("final 3")
  {
    sim.addPars(parsA);
    sim.addPoint(p3, parsA);
    sim.evolve(parsA, p1);
    auto result = sim.final();
    CHECK(result.x == doctest::Approx(7.33).epsilon(0.05));
    CHECK(result.y == doctest::Approx(11.30).epsilon(0.05));
    CHECK(result.H == doctest::Approx(36.18).epsilon(0.05));
  }

  SUBCASE("check Nth step values in case 1")
  {
    sim.addPars(parsA);
    sim.addPoint(p1, parsA);
    sim.evolve(parsA, p1);
    auto nstep = sim.nstep();
    CHECK(nstep.x == doctest::Approx(17.66).epsilon(0.05));
    CHECK(nstep.y == doctest::Approx(11.40).epsilon(0.05));
    CHECK(nstep.H == doctest::Approx(52.72).epsilon(0.05));
  }

  SUBCASE("check Nth step values in case 2")
  {
    sim.addPars(parsA);
    sim.addPoint(p2, parsA);
    sim.evolve(parsA, p1);
    auto nstep = sim.nstep();
    CHECK(nstep.x == doctest::Approx(7.85).epsilon(0.05));
    CHECK(nstep.y == doctest::Approx(21.05).epsilon(0.05));
    CHECK(nstep.H == doctest::Approx(65.49).epsilon(0.05));
  }

  SUBCASE("check Nth step values in case 3")
  {
    sim.addPars(parsA);
    sim.addPoint(p3, parsA);
    sim.evolve(parsA, p1);
    auto nstep = sim.nstep();
    CHECK(nstep.x == doctest::Approx(8.87).epsilon(0.05));
    CHECK(nstep.y == doctest::Approx(10.57).epsilon(0.05));
    CHECK(nstep.H == doctest::Approx(36.18).epsilon(0.05));
  }
}
