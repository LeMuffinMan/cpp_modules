#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie()
{
  std::cout << "Destroying Zombie named " << this->_name << std::endl;
}

void Zombie::_announce(void) const
{
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
