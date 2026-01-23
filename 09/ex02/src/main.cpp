
#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage:" << std::endl;
    std::cout << argv[0] << " 3 5 9 7 4" << std::endl;
    std::cout << argv[0] << " `shuf -i 1-100000 -n 3000 | tr \"\\n\" \" \"`"
              << std::endl;
    std::cout << argv[0] << " \"-1\" \"2\"" << std::endl;
    std::cout << "For OSX USER:" << std::endl;
    std::cout << argv[0] << " `jot -r 3000 1 100000 | tr \'\\n\' \' \'`"
              << std::endl;
    return 1;
  }
  PmergeMe pmergeme;
  try {
    pmergeme.parse(argc, argv);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  if (pmergeme.isAlreadySorted())
      return 0;

  std::cout << "Before: ";
  pmergeme.printContainer();
  try {
    pmergeme.run();
  } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
  }
  std::cout << "After: ";
  pmergeme.printContainer();
  pmergeme.printPerf();
  return 0;
}

// data management part ?
// verifier si les perfs sont coherentes
// - clear les sous conteneurs ?
// - unite de temps ?
// - start du time ? data management ?

// fair une branche avec le debug step by step pour expliquer
// clean master pour n'avoir que le debug demande

// Comment gerer les cas 1 element ? on considere deja trie ?
