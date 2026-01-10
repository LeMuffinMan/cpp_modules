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

void subjectTestsWithList() {
  std::cout << "=== with std::list ===" << std::endl;

  std::list<int> lst;
  lst.push_back(5);
  lst.push_back(17);

  std::cout << lst.back() << std::endl;
  lst.pop_back();

  std::cout << lst.size() << std::endl;

  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(0);

  std::list<int>::iterator it = lst.begin();
  std::list<int>::iterator ite = lst.end();

  ++it;
  --it;

  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
}

void iteratorsTests() {

  std::cout << std::endl;
  std::cout << "=== iterators tests ===" << std::endl;
  {
    std::cout << "pushing in mstack : [Hello], [World], [from], [MutantStack]"
              << std::endl;
    MutantStack<std::string> mstack;
    mstack.push("Hello");
    mstack.push("World");
    mstack.push("from");
    mstack.push("MutantStack");

    std::cout << "pushing_back in lst : [Hello], [World], [from], [lst]"
              << std::endl;
    std::list<std::string> lst;
    lst.push_back("Hello");
    lst.push_back("World");
    lst.push_back("from");
    lst.push_back("lst");

    std::cout << "MutantStack reverse iteration: ";
    for (MutantStack<std::string>::reverse_iterator rit = mstack.rbegin();
         rit != mstack.rend(); ++rit) {
      std::cout << *rit << " ";
    }
    std::cout << std::endl;

    std::cout << "std::list reverse iteration: ";
    for (std::list<std::string>::reverse_iterator rit = lst.rbegin();
         rit != lst.rend(); ++rit) {
      std::cout << *rit << " ";
    }
    std::cout << std::endl;

    std::cout << "\nMutantStack forward iteration: ";
    for (MutantStack<std::string>::iterator it = mstack.begin();
         it != mstack.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "std::list forward iteration: ";
    for (std::list<std::string>::iterator it = lst.begin(); it != lst.end();
         ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
  {
    std::cout << std::endl;
    std::cout << "pushing [1] [2] [3] in mstack" << std::endl;
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    std::cout << "pushing [1] [2] [3] in lst" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    const MutantStack<int> &const_mstack = mstack;
    const std::list<int> &const_lst = lst;

    std::cout << std::endl << "Const MutantStack iteration: ";
    for (MutantStack<int>::const_iterator it = const_mstack.begin();
         it != const_mstack.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl << "Const std::list iteration: ";
    for (std::list<int>::const_iterator it = const_lst.begin();
         it != const_lst.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl << "Const MutantStack reverse iteration: ";
    for (MutantStack<int>::const_reverse_iterator rit = const_mstack.rbegin();
         rit != const_mstack.rend(); ++rit) {
      std::cout << *rit << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl << "Const std::list reverse iteration: ";
    for (std::list<int>::const_reverse_iterator rit = const_lst.rbegin();
         rit != const_lst.rend(); ++rit) {
      std::cout << *rit << " ";
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
