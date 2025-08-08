// qui DICHIARO solamente gli oggetti

#ifndef FN_FINAL_HPP
#define FN_FINAL_HPP

#include <vector>

namespace fn {

struct Point
{
  double x;
  double y;
};

struct Result
{
  double x;
  double y;
  double H;
};

struct Pars
{
  double A;
  double B;
  double C;
  double D;
  size_t N;
  double delta_t;
  size_t nstep;
};

class Simulation
{
  std::vector<Point> points_;

  Pars pars_;

 public:
  size_t size() const;

  void addPars(const Pars& pars);

  void addPoint(Point const&);

  void addPoint(double x, double y);

  const std::vector<Point>& points() const;

  void evolve(Pars const&, Point&);

  Result final() const;

  Result nstep() const;
};

Result final(Result const&);

Result nstep(Result const&);

} // namespace fn

#endif