#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal()
{
    _type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->_type = other._type;
	this->_brain = new Brain(*(other._brain));
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        *this->_brain = *other._brain;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

Brain *Dog::getBrain( void ) const
{
	return (this->_brain);
}
