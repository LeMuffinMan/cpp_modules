#include "MutantStack.hpp"
// #include "MutantStack.tpp"
#include <iostream>
#include <list>

void subjectTests();
void subjectTestsLst();
void iteratorsTests();
void largeStackTest();
void subjectTestsWithList();

int main() {
  subjectTests();
  // subjectTestsLst();
  subjectTestsWithList();
  iteratorsTests();
  largeStackTest();
}
