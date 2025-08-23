#ifndef FN_FINAL_HPP
#define FN_FINAL_HPP

#include <vector>

namespace fn {

struct UserPoint
{
  double x;
  double y;
};

struct InternalPoint
{
  double xrel;
  double yrel;
  double H;
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
};

class Simulation
{
  std::vector<InternalPoint> points_;
  bool parameters_added_ = false;
  Pars pars_;
  UserPoint p0_;

 public:
  size_t size() const;

  void addPars(const Pars&);

  void addUserPoint(UserPoint const&);

  void evolve();

  const std::vector<InternalPoint>&
  points() const; // note: not strictly necessary, but one might want to know
                  // the internal representation vector for later analysis

  std::vector<Result> result() const;
};

std::vector<Result> result(std::vector<Result> const& res);

} // namespace fn

#endif