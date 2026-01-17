#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
// #include <string>
#include <vector>

class PmergeMe {
private:
  std::vector<int> _vec;
  std::deque<int> _deq;
  double _vectorTime;
  double _dequeTime;

  template <typename Container> void makePairs(Container &container);
  template <typename Container> void sortPairs(Container &container);
  template <typename Container> void buildMainChain(Container &container);
  template <typename Container> void insertPending(Container &container);
  template <typename Container>
  std::size_t binarySearch(const Container &container, int value, std::size_t end);
  template <typename Container> void fordJohnsonSort(Container &container);

  void printPerf();
  void printContainer();
public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void parse(int argc, char **argv);
  void run(double time_to_parse);
};

#endif
