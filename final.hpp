// qui DICHIARO solamente gli oggetti

#ifndef FN_FINAL_HPP
#define FN_FINAL_HPP

#include <vector>

namespace fn {

struct Point
{
  double xrel;
  double yrel;
  double H; // da implementare in evolve() e nel risultato finale!!!
};

struct Result
{
  double x;
  double y;
  double H;
}; // verificare che convenga per chiarezza, o se conviene un'unica classe
   // "Point" (anche se concettualmente una ha le coordinate riscalate, l'altra
   // no)?

struct Pars
{
  double A;
  double B;
  double C;
  double D;
  size_t N;
  double delta_t;
  size_t nstep; // eliminare!
};

class Simulation
{
  std::vector<Point> points_;

  Pars pars_;

 public:
  size_t size() const;

  void addPars(const Pars& pars);

  void addPoint(Point const&, Pars pars);

  // void addPoint(double x0, double y0); // eventualmente da implementare con
  // relativi test?

  const std::vector<Point>& points() const; //

  void evolve(Pars const& pars, Point&);

  Result final() const;

  Result nstep() const;

  // opzionale: aggiungere stima errore per ciascun punto, visualizzazione grafica di x(t) e y(t)
};

Result final(Result const&);

Result nstep(Result const&);

} // namespace fn

#endif