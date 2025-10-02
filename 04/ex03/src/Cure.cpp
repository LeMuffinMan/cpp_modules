#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("Cure") {}

Cure::~Cure() throw() {}

Cure *Cure::clone() const {
  return new Cure(*this);
}

void Cure::use(ICharacter &target) {
  std::cout << "Cure " << target.getName() << "'s illness" << std::endl;
}
