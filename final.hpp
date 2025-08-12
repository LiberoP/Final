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

 public:
  size_t size() const;

  void addPars(const Pars& pars);

  void addUserPoint(UserPoint const&);

  void evolve();

  const std::vector<InternalPoint>&
  points() const; // note: not necessary, but one might want to know the
                  // internal representation vector for analysis

  std::vector<Result> result() const;

  // OPZIONALE: aggiungere stima errore per ciascun punto, visualizzazione
  // grafica di x(t) e y(t)
};

std::vector<Result> result(std::vector<Result> const& res);

} // namespace fn

#endif