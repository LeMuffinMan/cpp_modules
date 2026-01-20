#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
// #include <string>
#include <vector>

class PmergeMe {
private:
  std::vector<int> _vec;
  std::deque<int> _deq;
  double _vecTime;
  double _deqTime;

  template <typename Container> void fordJohnsonSort(Container &container);
  template <typename Container> void swapPairs(Container &container);
  template <typename Container> void sortPairs(Container &container);
  template <typename Container>
  void buildMainChain(Container &container, Container &mainChain,
                      Container &pend);
  template <typename Container>
  void generateJacobsthal(std::size_t n, Container &jacobsthal);
  template <typename Container>
  void createInsertionOrder(std::size_t pendSize, Container &order);
  template <typename Container>
  std::size_t binarySearch(const Container &container, int value,
                           std::size_t end);

  void printPerf();
  template <typename Container> void insertPending(Container &container);

public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void printContainer();
  void parse(int argc, char **argv);
  void run();
};

#endif
