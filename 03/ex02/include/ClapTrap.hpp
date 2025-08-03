#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:
    ClapTrap(std::string name); // Default constructor
    ClapTrap(const ClapTrap& other); // Copy constructor
    ClapTrap& operator=(const ClapTrap& other); // Copy assignment
    ~ClapTrap(); // Destructor

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
    // Add private members here
};

#endif
