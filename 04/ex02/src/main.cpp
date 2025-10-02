#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{

    std::cout << std::endl << "========== AAnimals Tests ===========" << std::endl << std::endl;
    {
        AAnimal* animals[10];

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

        std::cout << std::endl;
        std::cout << "minou brain adress : " << minou->getBrain() << std::endl;
        std::cout << "minou_copy brain adress : " << minou_copy.getBrain() << std::endl;
        std::cout << "toutou brain adress: " << toutou->getBrain() << std::endl;
        std::cout << "toutou_copy brain adress: " << toutou_copy.getBrain() << std::endl;
        std::cout << std::endl;

        delete minou;
        delete toutou;
    }

    {
        // AAnimal unicorn;
        // We cant instantiate AAnimal so we won't create any unicorn
    }
    return 0;
}

