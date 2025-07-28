#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie()
{
  delete this;
}

void Zombie::setName(std::string name)
{
  this->_name = name;
}

void Zombie::announce(void) const
{
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
