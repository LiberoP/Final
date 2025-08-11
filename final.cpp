//  qui DEFINISCO gli oggetti già dichiarati
#include "final.hpp"

#include <cmath>
#include <numeric>
#include <stdexcept>

namespace fn {
size_t Simulation::size() const
{
  return points_.size();
}

void Simulation::addPars(const Pars& pars)
{
  pars_ = pars;

  if ((pars.A <= 0) | (pars.B <= 0) | (pars.C <= 0) | (pars.D <= 0)) {
    throw std::runtime_error{"Non-positive starting equation parameters"};
  }

  else if ((pars.N < 1) | (pars.delta_t <= 0)) {
    throw std::runtime_error{"Invalid steps parameters"};
  }

  points_.resize(pars.N + 1);
}

void Simulation::addUserPoint(UserPoint const& p0, Pars pars)
{
  pars_        = pars;
  auto const s = size();
  if (s < 1) {
    throw std::runtime_error{"Null starting point"};
  }

  else if ((p0.x <= 0) | (p0.y <= 0)) {
    throw std::runtime_error{"Negative starting point"};
  }

  points_[0] = {
      p0.x * pars.C / pars.D, p0.y * pars.B / pars.A,
      -pars_.D * log(p0.x) + pars_.C * p0.x + pars_.B * p0.y
          - pars_.A * log(p0.y)}; // note: H of initial i=0 point is calculated
                                  // from the initial (user) coordinates
}

const std::vector<InternalPoint>& Simulation::points() const
{
  return points_;
}

void Simulation::evolve(Pars const& pars)
{
  pars_        = pars;
  auto const s = size();
  for (size_t i = 1; i < s; ++i) {
    double xrel = points_[i - 1].xrel
                + pars.A * (1 - points_[i - 1].yrel) * points_[i - 1].xrel
                      * pars.delta_t;
    double yrel = points_[i - 1].yrel
                + pars.D * (points_[i - 1].xrel - 1) * points_[i - 1].yrel
                      * pars.delta_t;

    double H =
        -pars_.D * log(xrel * pars.D / pars.C) + xrel * pars.D + yrel * pars.A
        - pars_.A
              * log(yrel * pars.A
                    / pars.B); // note: H of i=1,2,3,... point is calculated
                               // from internal (relative) coordinates

    points_[i] = {xrel, yrel, H};
  }
}

std::vector<Result> Simulation::result(Pars const& pars)
{
  auto const s = size();
  result_.resize(s);
  for (size_t i = 0; i < s; ++i) {
    result_[i] = {fabs(points_[i].xrel) * pars.D / pars.C,
                  fabs(points_[i].yrel) * pars.A / pars.B, fabs(points_[i].H)};
  }
  return result_;
}

std::vector<Result> result(std::vector<Result> const& res)
{
  return res;
}

} // namespace fn
