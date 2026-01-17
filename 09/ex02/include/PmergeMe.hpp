#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>

class PmergeMe {
private:
  std::vector<int> _vec;
  std::deque<int> _deq;

  double _vectorTime;
  double _dequeTime;

public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void parse(int argc, char **argv);
  void run();
};

template <typename Container>
class Solver {
private:
    Container _data;
    Container _mainChain;

    void makePairs();
    void sortPairs();
    void recursiveSort(size_t start, size_t end);
    void insertPending();
    size_t binarySearch(int value, size_t end);

public:
    Solver() {}
    Solver(const Container& input) : data(input) {}

    void sort();
    const Container& getResult() const { return mainChain; }
    double getExecutionTime() const;
};

#endif
