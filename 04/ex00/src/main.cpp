#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Regular tests =====" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << std::endl << "-- Types --" << std::endl;
        std::cout << meta->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << std::endl << "-- makeSound() --" << std::endl;
        j->makeSound();
        i->makeSound();
        meta->makeSound();
        std::cout << std::endl;
        delete j;
        delete i;
        delete meta;
    }
    std::cout << std::endl << "===== Wrong tests =====" << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* j = new WrongDog();
        const WrongAnimal* i = new WrongCat();
        std::cout << std::endl;
        std::cout << "-- Types --" << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << meta->getType() << " " << std::endl;
        std::cout << std::endl;
        std::cout << "-- makeSound() --" << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        std::cout << std::endl;
        delete j;
        delete i;
        delete meta;
    }
    return 0;
}

