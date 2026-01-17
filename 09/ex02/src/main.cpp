
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
  //start time
  try {
    pmergeme.parse(argc, argv);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  double time_to_parse = now - start_time;
  std::cout << "Before: ";
  pmergeme.printContainer();
  pmergeme.run(time_to_parse);
  std::cout << "After: ";
  pmergeme.printContainer();
  return 0;
}
