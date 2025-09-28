
#include "ClapTrap.hpp"

int main() {
    ClapTrap bob("Bob");

    bob.attack("Target1");
    bob.takeDamage(3);
    bob.beRepaired(2);
    bob.attack("Target2");
    bob.attack("Target2");
    bob.attack("Target2");
    bob.attack("Target2");
    bob.attack("Target2");
    bob.attack("Target2");
    bob.attack("Target2");
    bob.attack("Target2");
    bob.attack("Target2");
    bob.beRepaired(5);  
    bob.takeDamage(42);
    bob.beRepaired(5);  
    bob.attack("Target2");
}

