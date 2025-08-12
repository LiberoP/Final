// programma "madre"

#include "final.hpp"

#include <cstdlib>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>

int main()
{
  try {
    fn::Simulation sim;

    std::ifstream infile{"../final/input.txt"};

    if (!infile) {
      throw std::runtime_error{"Impossible to open file!"};
    }

    double A, B, C, D;
    size_t N;
    double delta_t;
    double x0, y0;

    while (infile >> A >> B >> C >> D >> N >> delta_t >> x0 >> y0) {
      sim.addPars({A, B, C, D, N, delta_t});
      sim.addUserPoint({x0, y0}, {A, B, C, D, N, delta_t});
      sim.evolve();
    }
    fn::Pars pars = {A, B, C, D, N, delta_t};
    auto res      = sim.result();

    std::ofstream outfile{"Results.txt"};

    if (!outfile) {
      throw std::runtime_error{"Impossible to open file"};
    }

    outfile << std::left << std::setw(10) << "Time, t" << std::setw(25)
            << "Density of preys, x(t)" << std::setw(25)
            << "Density of predators, y(t)" << std::setw(30)
            << "Integral H(x,y)" << "\n";

    auto s = res.size();
    for (size_t i = 0; i < s; ++i) {
      const auto t_i = pars.delta_t * i; // risolvere warning conversione!
      outfile << std::setw(10) << t_i << std::setw(25) << res[i].x
              << std::setw(25) << res[i].y << std::setw(30) << res[i].H << "\n"; // risolvere problema spaziatura finale!
    }

  } catch (std::exception const& e) {
    std::cerr << "Caught exception: '" << e.what() << "'\n";
    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "Caught unknown exception\n";
    return EXIT_FAILURE;
  }
}