#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
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
    
    //ajouter les wrong tests 

    //ajouter des tests pour prouver la deep copy
    //afficher l'adresse des brains
    //afficher les ideas et montrer que ce sont bien les memes 

    return 0;
}

