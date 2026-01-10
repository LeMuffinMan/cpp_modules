#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

int main() {
  std::cout << "pushing in vec : [0] -> 1, [1] -> 2, [2] -> 3, [3] -> 4"
            << std::endl;
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  std::cout << "searching 3 in vec :" << std::endl;
  try {
    int res = easyfind(vec, 3);
    std::cout << "Found in vector at index: " << res << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "searching -3 in vec :" << std::endl;
  try {
    int res = easyfind(vec, -3);
    std::cout << "Found in vector at index: " << res << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl
            << "pushing in lst: [0] -> 10, [1] -> 20, [2] -> 30, [3] -> 42"
            << std::endl;
  std::list<int> lst;
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  lst.push_back(42);

  std::cout << std::endl << "searching 42 in lst :" << std::endl;
  try {
    int res = easyfind(lst, 42);
    std::cout << "Found in list at index: " << res << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "searching 41 in lst :" << std::endl;
  try {
    int res = easyfind(lst, 41);
    std::cout << "Found in list at index: " << res << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl
            << "pushing in deq: [0] -> 5, [1] -> 6, [2] -> 7" << std::endl;
  std::deque<int> deq;
  deq.push_back(5);
  deq.push_back(6);
  deq.push_back(7);

  std::cout << "searching 6 in deq :" << std::endl;
  try {
    int res = easyfind(deq, 6);
    std::cout << "Found in deque at index: " << res << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "searching 8 in deq :" << std::endl;
  try {
    int res = easyfind(deq, 8);
    std::cout << "Found in deque at index: " << res << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
