#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "idea";
    }
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

