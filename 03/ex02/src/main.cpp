
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ClapTrap carl("Carl");
    ScavTrap seb("Seb");
    FragTrap fred("Fred");

    carl.takeDamage(3);
    carl.beRepaired(2);
    for (int i = 0; i < 10; ++i)
    {
        carl.attack("Target2");
    }
    carl.beRepaired(5);
    carl.takeDamage(42); 
    carl.beRepaired(5);
    carl.attack("Target2");
    std::cout << std::endl << "===============" << std::endl << std::endl;
    seb.guardGate();
    seb.takeDamage(3);
    seb.beRepaired(2);
    for (int i = 0; i < 50; ++i)
    {
        seb.attack("Target2");
    }
    seb.beRepaired(5);
    seb.takeDamage(142); 
    seb.beRepaired(5);
    seb.attack("Target2");
    std::cout << std::endl << "===============" << std::endl << std::endl;
    fred.highFiveGuys();
    fred.takeDamage(3);
    fred.beRepaired(2);
    for (int i = 0; i < 100; ++i)
    {
        fred.attack("Target2");
    }
    fred.beRepaired(5);
    fred.takeDamage(142); 
    fred.beRepaired(5);
    fred.attack("Target2");
}
