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
  points_.resize(pars_.N + 1);
}

void Simulation::addPoint(Point const& p0)
{
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
  if (s < 1) {
    throw std::runtime_error{"Null starting point"};
  }

  for (int i = 1; i < s; ++i) {
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
  return Result{finalp.x, finalp.y, finalH};
}

Result Simulation::nstep() const
{
  int n     = pars_.nstep;
  Point np  = {points_[n].x * pars_.D / pars_.C,
               points_[n].y * pars_.A / pars_.B};
  double nH = -pars_.D * log(points_[n].x) + pars_.C * points_[n].x
            + pars_.B * points_[n].y - pars_.A * log(points_[n].y);
  return Result{np.x, np.y, nH};
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

// namespace fn
