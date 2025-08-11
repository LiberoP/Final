// qui DICHIARO solamente gli oggetti

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
  // size_t nstep;
};

class Simulation
{
  std::vector<InternalPoint> points_;

  Pars pars_;

 public:
  size_t size() const;

  void addPars(const Pars& pars);

  void addUserPoint(UserPoint const&, Pars pars);

  // void addPoint(double x0, double y0); // eventualmente da implementare con
  // relativi test?

  const std::vector<InternalPoint>& points() const;

  void evolve(Pars const& pars);

  std::vector<Result> result_;

  std::vector<Result> result(Pars const& pars);

  // Result nstep() const;

  // OPZIONALE: aggiungere stima errore per ciascun punto, visualizzazione
  // grafica di x(t) e y(t)
};

std::vector<Result> result(std::vector<Result> const& res);

// Result nstep(Result const&);

} // namespace fn

#endif