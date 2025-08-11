// programma "madre"

#include "final.hpp"

#include <cstdlib>
#include <exception>
#include <fstream> // per scrittura su file
#include <iostream>

int main()
{
  try {
    fn::Simulation sim;

  } catch (std::exception const& e) {
    std::cerr << "Caught exception: '" << e.what() << "'\n";
    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "Caught unknown exception\n";
    return EXIT_FAILURE;
  }

  // std::ofstream out("Simulation results.txt");
}

// aggiungere parte per stampare su file / su schermo!!!

// CHIEDERE per implementazione più efficiente!