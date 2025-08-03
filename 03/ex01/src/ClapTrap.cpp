#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
    _name = name;
    _hitPoints = 10; // 100 ?
    _energyPoints = 10; // 50 ?
    _attackDamage = 0; // 20 ?
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    _hitPoints = other._hitPoints; 
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _hitPoints = other._hitPoints; 
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << _name << " takes " << amount << " points of damage" << std::endl;
    _hitPoints = _hitPoints - amount; 
    if (_hitPoints < 0)
        std::cout << _name << " just died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << _name << " repairs " << amount << " hit points" << std::endl;
        _hitPoints = _hitPoints + amount; 
        _energyPoints--;
    }
    else 
    {
        if (_hitPoints < 0)
            std::cout << _name << " tried to repair but has not enough Hit Points." << std::endl;
        else
            std::cout << _name << " tried to repair but has not enough Energy Points." << std::endl;
    }
}

