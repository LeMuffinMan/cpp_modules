#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}  

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
  std::cout << "ScavTrap copy constructor called" << std::endl;
  *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
      ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
  std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
    {
        if (_hitPoints < 0)
            std::cout << _name << " tried to attack but has not enough Hit Points." << std::endl;
        else
            std::cout << _name << " tried to attack but has not enough Energy Points." << std::endl;
    }
}
