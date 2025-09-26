
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB (std::string name)  : name(name) {}

void HumanB::setWeapon(Weapon& weapon)
{
  weapon = &weapon;
}

void HumanB::attack()
{
  if (_weapon)
    std::cout << name << " attacks with " << weapon->getType() << std::endl;
  else
    std::cout << name << " has no weapon to attack with!" << std::endl;
}
