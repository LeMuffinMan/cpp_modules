#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Regular tests =====" << std::endl;
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

    AMateria* tmp;
    tmp = src->createMateria("ice");
    player1->equip(tmp);
    tmp = src->createMateria("cure");
    player1->equip(tmp);

    //If we wrote a Wizard class and a Warrior class, we could use multi heritages to create two Characters, with specifics methods and members
    ICharacter* player2 = new Character("player2");
    tmp = src->createMateria("cure");
    player2->equip(tmp);
    tmp = src->createMateria("ice");
    player2->equip(tmp);


    std::cout << "-- player 1's turn --" << std::endl;
    player1->use(0, *player2);
    player1->use(1, *player2);
    std::cout << std::endl;
    std::cout << "-- player 2's turn --" << std::endl;
    player2->use(0, *player1);
    player2->use(1, *player1);

    std::cout << "\n===== Inventory tests =====" << std::endl;

    //let's fill and overflow the inventory
    for (int i = 0; i < 5; i++) {
        AMateria* extra = src->createMateria("ice");
        player1->equip(extra);
    }
    
    //the slot 1 should still have the cure Materia, and no leaks should appear
    dynamic_cast<Character*>(player1)->printInventory();

    //use a valid and invalid inventory slot
    player1->use(3, *player2);   
    player1->use(10, *player2);

    player2->use(1, *player1);   
    player2->use(10, *player1);

    //Each Character floor should have the dropped Materia
    player1->unequip(2);
    player2->unequip(0);

    //This should not create any error, and nothing should be added to each Character's floor 
    player1->unequip(10);
    player2->unequip(4);

    //Let's debug what materias are equiped on player1, and if the floor handles correctly unequiped AMateria tracking for each player
    std::cout << std::endl;
    dynamic_cast<Character*>(player1)->printInventory();
    std::cout << std::endl;
    dynamic_cast<Character*>(player2)->printInventory();
    //dynamic_cast is needed since ICharacter does not know the method. But Character class does
    //if we created a Character from the interface ICharacter, this should work without errors 

    delete player2;
    delete player1;
    delete src;

    return 0;
}
