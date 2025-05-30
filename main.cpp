// programma "madre"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <random> // serve?

#include "fstream"
#include "final.hpp" 


int main() {
  try {
    // ...
    

  } catch (std::exception const &e) {
    std::cerr << "Caught exception: '" << e.what() << "'\n";
    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "Caught unknown exception\n";
    return EXIT_FAILURE;
  }
}