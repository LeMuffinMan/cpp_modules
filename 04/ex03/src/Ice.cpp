#include "Ice.hpp"
#include "ICharacter.hpp" 
#include <iostream>

Ice::Ice() : AMateria("Ice") {}

Ice::~Ice() {}

Ice *Ice::clone() const {
  return new Ice(*this);
}

void Ice::use(ICharacter &target) {
  std::cout << "FREEZE !" << std::endl;
  std::cout << target.getName() << "is frozen" << std::endl;
}


