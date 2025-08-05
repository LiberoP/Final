//  qui DEFINISCO gli oggetti già dichiarati
#include "final.hpp"

#include <numeric>
#include <stdexcept>

namespace fn {
size_t Simulation::size() const
{
  return points_.size();
}

void Simulation::addPoint(double x, double y)
{
  addPoint(Point{x, y});
}
{
  points_.push_back(p0);
}

// DA QUI riempire un vettore di N elementi con il point i calcolato in ogni
// i=0,1,2,...N-1 a partire dal point i-1; risultato sarà l'elemento finale con
// calcolo di H, nth point sarà l'nth point con calcolo di H

} // namespace fn
