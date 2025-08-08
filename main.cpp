// programma "madre"

#include "final.hpp"

#include <cstdlib>
#include <exception>
#include <fstream> // serve?
#include <iostream>
#include <random> // serve?

int main()
{
  try {
    fn::Simulation sim;

  } catch (std::exception const& e) {
    std::cerr << "Caught exception: '" << e.what() << "'\n";
    return EXIT_FAILURE; // da cambiare: non serve uscire dal programma!
  } catch (...) {
    std::cerr << "Caught unknown exception\n";
    return EXIT_FAILURE; // da cambiare: non serve uscire dal programma!
  }
}

// aggiungere parte per stampare su file / su schermo!