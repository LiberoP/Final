// qui DICHIARO solamente gli oggetti

#ifndef FN_FINAL_HPP
#define FN_FINAL_HPP

#include <vector>

namespace fn {

struct Point
{
  int x;
  int y;
};

struct Result
{
  Point p;
  double H;
};

struct Pars
{
  double A;
  double B;
  double C;
  double D;
  double N;
  double delta_t;
};

class Simulation
{
  std::vector<Point> points_;

 public:
  size_t size() const;

  const std::vector<Point>& points() const;

  void addPars(Pars const&);

  void addPoint(Point const&);

  void evolve(Pars const&, Point&);

  Result final() const;

  Result nstep() const;
};

Result final(Simulation const&);

Result nstep(Simulation const&);

} // namespace fn
#endif