#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>

class PmergeMe {
private:
  std::vector<int> _vec;
  std::deque<int> _deq;

public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void parse(int argc, char **argv);
};

#endif
