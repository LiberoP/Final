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
  parameters_added_ = true;

  pars_ = pars;

  if ((pars_.A <= 0) || (pars_.B <= 0) || (pars_.C <= 0) || (pars_.D <= 0)) {
    throw std::runtime_error{"Non-positive starting equation parameters"};
  }

  else if ((pars_.N < 1) || (pars_.delta_t <= 0)) {
    throw std::runtime_error{"Invalid steps parameters"};
  }
}

void Simulation::addUserPoint(UserPoint const& p0)
{
  if (!parameters_added_) {
    throw std::runtime_error{"No parameters added"};

  } else if ((p0.x <= 0) || (p0.y <= 0)) {
    throw std::runtime_error{"Non-positive starting point"};
  }

  points_.resize(pars_.N + 1);

  points_[0] = {
      p0.x * pars_.C / pars_.D, p0.y * pars_.B / pars_.A,
      -pars_.D * log(p0.x) + pars_.C * p0.x + pars_.B * p0.y
          - pars_.A * log(p0.y)}; // note: H of initial i=0 point is calculated
                                  // from the initial (user) coordinates
}

void Simulation::evolve()
{
  auto const s = size();

  if (s < 1) {
    throw std::runtime_error{"No point added"};
  }

  for (size_t i = 1; i < s; ++i) {
    double xrel = points_[i - 1].xrel
                + pars_.A * (1 - points_[i - 1].yrel) * points_[i - 1].xrel
                      * pars_.delta_t;
    double yrel = points_[i - 1].yrel
                + pars_.D * (points_[i - 1].xrel - 1) * points_[i - 1].yrel
                      * pars_.delta_t;

    double H =
        -pars_.D * log(xrel * pars_.D / pars_.C) + xrel * pars_.D
        + yrel * pars_.A
        - pars_.A
              * log(yrel * pars_.A
                    / pars_.B); // note: H of i=1,2,3,... point is calculated
                                // from internal (relative) coordinates

    points_[i] = {xrel, yrel, H};
  }
}

const std::vector<InternalPoint>& Simulation::points() const
{
  return points_;
}

std::vector<Result> Simulation::result() const
{
  std::vector<Result> result_;
  auto const s = size();
  result_.resize(s);
  for (size_t i = 0; i < s; ++i) {
    result_[i] = {fabs(points_[i].xrel) * pars_.D / pars_.C,
                  fabs(points_[i].yrel) * pars_.A / pars_.B,
                  fabs(points_[i].H)};
  }
  return result_;
}

std::vector<Result> result(const Simulation& sim)
{
  return sim.result();
} // note: to process results outside of class

} // namespace fn