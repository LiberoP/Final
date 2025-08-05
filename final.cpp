//  qui DEFINISCO gli oggetti già dichiarati
#include "final.hpp"

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
  points_[0] = p0;
}

void Simulation::addPoint(double x, double y)
{
  addPoint(Point{x, y});
}

const std::vector<Point>& Simulation::points() const
{
  return points_;
}

// DA QUI riempire un vettore di N elementi con il point i calcolato in ogni
// i=0,1,2,...N-1 a partire dal point i-1; risultato sarà l'elemento finale con
// calcolo di H, nth point sarà l'nth point con calcolo di H

Result Simulation::final() const
{
  auto const N = size();
  if N
    = 0
    {
      throw std::runtime_error{"Null starting point"};
    }
}

} // namespace fn
