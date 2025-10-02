#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{

    std::cout << std::endl << "========== Animals Tests ===========" << std::endl << std::endl;
    {
        Animal* animals[10];

        for (int i = 0; i < 10; i++) {
            if (i < 5) {
                animals[i] = new Dog;
            } else {
                animals[i] = new Cat;
            }
        }

        //normal tests
        for (int i = 0; i < 10; i++) {
            animals[i]->makeSound();
        }
        
        for (int i = 0; i < 10; i++) {
            delete animals[i];
        }

    }

    std::cout << std::endl << "========== Wrong Animals Tests ===========" << std::endl << std::endl;

    {
        WrongAnimal* animals[10];

        for (int i = 0; i < 10; i++) {
            if (i < 5) {
                animals[i] = new WrongDog;
            } else {
                animals[i] = new WrongCat;
            }
        }

        for (int i = 0; i < 10; i++) {
            animals[i]->makeSound();
        }
        
        for (int i = 0; i < 10; i++) {
            delete animals[i];
        }
    }

    std::cout << std::endl << "========== Deep copy Tests ===========" << std::endl << std::endl;
    //deep copy test
    {
        Cat *minou = new Cat();
        Dog *toutou = new Dog();
        Cat minou_copy = *minou;
        Dog toutou_copy = *toutou;

        std::cout << "minou brain adress : " << minou->getBrain() << std::endl;
        std::cout << "minou_copy brain adress : " << minou_copy.getBrain() << std::endl;
        std::cout << "toutou brain adress: " << toutou->getBrain() << std::endl;
        std::cout << "toutou_copy brain adress: " << toutou_copy.getBrain() << std::endl;


    }
    
    //afficher les ideas et montrer que ce sont bien les memes 

    return 0;
}

