#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Character* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    Character* bob = new Character("bob");

    // utiliser les materias
    me->use(0, *bob);
    me->use(1, *bob);
    //This tries to use an empty slot materia
    me->use(2, *bob);

    std::cout << "\n===== Overflow inventory =====" << std::endl;
    for (int i = 0; i < 5; i++) {
        tmp = src->createMateria("ice");
        me->equip(tmp); // le 5ème tombe au sol
    }

    // test unequip et floor
    me->unequip(0); // doit tomber au sol

    // afficher inventaire et floor
    me->printInventory();

    std::cout << "\n===== Deep copy =====" << std::endl;
    Character* clone = new Character(*me);
    clone->printInventory();

    std::cout << "\n===== Check addresses =====" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "Original slot " << i << ": " << me->_inventory[i] 
                  << " | Clone slot " << i << ": " << clone->_inventory[i] << std::endl;
    }

    delete clone;
    delete bob;
    delete me;
    delete src;

    return 0;
}

