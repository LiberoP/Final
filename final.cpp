//  qui DEFINISCO gli oggetti già dichiarati
#include "final.hpp"

#include <algorithm> // serve?
#include <cmath>
#include <numeric>
#include <stdexcept> // serve?

namespace fn {
size_t Simulation::size() const
{
  return points_.size();
}

void Simulation::addPars(const Pars& pars)
{
  pars_ = pars;

  if ((pars_.A <= 0) | (pars_.B <= 0) | (pars_.C <= 0) | (pars_.D <= 0)
      | (pars_.N < 1) | (pars_.delta_t <= 0)) {
    throw std::runtime_error{
        "Non-positive starting equation / steps parameters"};
  }

  else if ((pars_.nstep < 1) | (pars_.nstep > pars_.N)) {
    throw std::runtime_error{"Too low / high nth-step"};
  }

  points_.resize(pars_.N + 1);
}

void Simulation::addPoint(Point const& p0)
{
  auto const s = size();
  if (s < 1) {
    throw std::runtime_error{"Null starting point"};
  }

  else if ((p0.x <= 0) | (p0.y <= 0)) {
    throw std::runtime_error{"Negative starting point"};
  }

  points_[0] = {p0.x * pars_.C / pars_.D, p0.y * pars_.B / pars_.A};
}

void Simulation::addPoint(double x0, double y0)
{
  addPoint(Point{x0, y0});
}

const std::vector<Point>& Simulation::points() const
{
  return points_;
}

void Simulation::evolve(Pars const&, Point&)
{
  auto const s = size();
  for (size_t i = 1; i < s; ++i) {
    points_[i] = {points_[i - 1].x
                      + pars_.A * (1 - points_[i - 1].y) * points_[i - 1].x
                            * pars_.delta_t,
                  points_[i - 1].y
                      + pars_.D * (points_[i - 1].x - 1) * points_[i - 1].y
                            * pars_.delta_t};
  }
}

Result Simulation::final() const
{
  Point finalp  = {points_.back().x * pars_.D / pars_.C,
                   points_.back().y * pars_.A / pars_.B};
  double finalH = -pars_.D * log(finalp.x) + pars_.C * finalp.x
                + pars_.B * finalp.y - pars_.A * log(finalp.y);
  return Result{fabs(finalp.x), fabs(finalp.y), fabs(finalH)};
}

Result Simulation::nstep() const
{
  auto n     = pars_.nstep;
  Point np  = {points_[n].x * pars_.D / pars_.C,
               points_[n].y * pars_.A / pars_.B};
  double nH = -pars_.D * log(points_[n].x) + pars_.C * points_[n].x
            + pars_.B * points_[n].y - pars_.A * log(points_[n].y);
  return Result{fabs(np.x), fabs(np.y), fabs(nH)};
}

Result final(Result const& res)
{
  return res;
}

Result nstep(Result const& nst)
{
  return nst;
}

} // namespace fn
