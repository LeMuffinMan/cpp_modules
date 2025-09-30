
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ClapTrap bob("Bob");
    ScavTrap jim("Jim");

    bob.takeDamage(3);
    bob.beRepaired(2);
    for (int i = 0; i < 10; ++i)
    {
        bob.attack("Target1");
    }
    bob.beRepaired(2);
    bob.takeDamage(42); 
    bob.beRepaired(5);
    bob.attack("Target1");
    std::cout << std::endl << "===============" << std::endl << std::endl;
    jim.guardGate();
    jim.takeDamage(3);
    jim.beRepaired(2);
    for (int i = 0; i < 50; ++i)
    {
        jim.attack("Target2");
    }
    jim.beRepaired(5);
    jim.takeDamage(142); 
    jim.beRepaired(5);
    jim.attack("Target2");
}

