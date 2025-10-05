#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    //create a new interface so we can use it to blueprint AMaterias
    //thus, we could easily and safely add a Fire AMateria that would behave the same way as other materias
    //But we MUST implement the .hpp .cpp for Fire 
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    //Since interfaces does not have any member, we could use it to have class with multiple heritages :
    //All characters have their own name, but they could be a wizard, or a warrior, or a healer ... each one with specific methodes and members
    //May be a warrior would not be allowed to do magic but use weapons instead, so we could create from IMateriaSource, using the learnMateria methode, a Weapon abstract class
    //The Interface guarantees each class built from it, share a same "contract" : they must be named since they are Characters
    //From this contract, each object could still heritate from other class and specify which type of character we want (wizard / warrior)
    ICharacter* player1 = new Character("player1");

    //If we wrote a Wizard class and a Warrior class, we could use multi heritages to create two Characters, with specifics methods and members
    ICharacter* player2 = new Character("player2");
    AMateria* tmp;

    std::cout << "=============inventory empty =============" << std::endl;
    
    std::cout << std::endl;
    dynamic_cast<Character*>(player1)->printInventory();
    std::cout << std::endl;
    dynamic_cast<Character*>(player2)->printInventory();

    tmp = src->createMateria("ice");
    player1->equip(tmp);
    tmp = src->createMateria("cure");
    player1->equip(tmp);
    tmp = src->createMateria("Unknown");
    player1->equip(tmp);
    tmp = src->createMateria("");
    player1->equip(tmp);

    std::cout << std::endl << "============= player 1's turn =============" << std::endl;
    player1->use(0, *player2);
    player1->use(1, *player2);
    std::cout << std::endl;

    tmp = src->createMateria("cure");
    player2->equip(tmp);
    tmp = src->createMateria("ice");
    player2->equip(tmp);

    std::cout << "============= player 2's turn =============" << std::endl;
    player2->use(0, *player1);
    player2->use(1, *player1);


    std::cout << std::endl;
    std::cout << "============= invalid use =============" << std::endl;
    player1->use(10, *player2);
    player2->use(-42, *player1);


    std::cout << std::endl;
    std::cout << "============= inventory overflow =============" << std::endl;

    for (int i = 0; i < 5; i++) {
        AMateria* extra = src->createMateria("ice");
        player1->equip(extra);
    }
    
    dynamic_cast<Character*>(player1)->printInventory();

    std::cout << std::endl;
    std::cout << "============= unequip tests =============" << std::endl;

    player1->unequip(2);
    player1->unequip(3);
    player2->unequip(0);

    std::cout << std::endl;
    dynamic_cast<Character*>(player1)->printInventory();
    std::cout << std::endl;
    dynamic_cast<Character*>(player2)->printInventory();

    std::cout << std::endl;
    std::cout << "============= unequip invalid index =============" << std::endl;

    player1->unequip(10);
    player2->unequip(4);

    std::cout << std::endl;
    dynamic_cast<Character*>(player1)->printInventory();
    std::cout << std::endl;
    dynamic_cast<Character*>(player2)->printInventory();

    delete player2;
    delete player1;
    delete src;

    return 0;
}

