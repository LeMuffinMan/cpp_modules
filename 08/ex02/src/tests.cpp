#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <iostream>
#include <list>

void subjectTests() {
  std::cout << "=== Subject tests ===" << std::endl;
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

void subjectTestsLst() {
  std::cout << std::endl;
  std::cout << "=== std::list ===" << std::endl;
  MutantStack<int> mstack;
  std::list<int> lst;

  for (int i = 0; i < 10; ++i) {
    mstack.push(i);
    lst.push_back(i);
  }

  std::cout << "MutantStack from begin to end: ";
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "std::list from begin to end: ";
  for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void iteratorsTests() {

  std::cout << std::endl;
  std::cout << "=== iterators tests ===" << std::endl;
  {
    MutantStack<std::string> mstack;
    mstack.push("Hello");
    mstack.push("World");
    mstack.push("from");
    mstack.push("MutantStack");

    std::cout << "MutantStack from end to begin: ";
    for (MutantStack<std::string>::reverse_iterator rit = mstack.rbegin();
         rit != mstack.rend(); ++rit) {
      std::cout << *rit << " ";
    }
    std::cout << std::endl;

    std::cout << "std::list from end to begin: ";
    for (MutantStack<std::string>::iterator it = mstack.begin();
         it != mstack.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
  {
    MutantStack<double> mstack;
    mstack.push(3.14);
    mstack.push(2.71);
    mstack.push(1.41);

    const MutantStack<double> &const_mstack = mstack;

    std::cout << "Const iteration: ";
    for (MutantStack<double>::const_iterator it = const_mstack.begin();
         it != const_mstack.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
}

void largeStackTest() {
  std::cout << std::endl;
  std::cout << "=== large stack ===" << std::endl;
  MutantStack<int> largeStack;
  for (int i = 0; i < 1000; ++i) {
    largeStack.push(i);
  }

  std::cout << "Size: " << largeStack.size() << std::endl;
  std::cout << "Top: " << largeStack.top() << std::endl;

  int sum = 0;
  for (MutantStack<int>::iterator it = largeStack.begin();
       it != largeStack.end(); ++it) {
    sum += *it;
  }
  std::cout << "Sum of all elements: " << sum << std::endl;
}
