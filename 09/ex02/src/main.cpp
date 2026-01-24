
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
