#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Regular tests =====" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n===== Inventory tests =====" << std::endl;

    for (int i = 0; i < 5; i++) {
        AMateria* extra = src->createMateria("ice");
        me->equip(extra);
    }

    me->use(3, *bob);   
    me->use(10, *bob);

    Character* meReal = dynamic_cast<Character*>(me);
    meReal->unequip(0);

    meReal->printInventory();

    std::cout << "\n===== Deep copy test =====" << std::endl;
    Character* clone = new Character(*meReal);

    for (int i = 0; i < 4; i++) {
        std::cout << "Original slot " << i << ": "
                  << meReal->getMateria(i)
                  << " | Clone slot " << i << ": "
                  << clone->getMateria(i) << std::endl;
    }

    std::cout << "\nOriginal inventory:" << std::endl;
    meReal->printInventory();
    std::cout << "\nCloned inventory:" << std::endl;
    clone->printInventory();

    delete clone;
    delete bob;
    delete me;
    delete src;

    return 0;
}


//virer les debugs contrcuteurs destructeurs
//revoir le main test 
