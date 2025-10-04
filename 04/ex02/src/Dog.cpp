#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() : AAnimal(), _brain(NULL)
{
    _type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->_type = other._type;
	if (other._brain) {
	    this->_brain = new Brain(*(other._brain));
	} else {
        this->_brain = new Brain;
	}
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type; 
        if (!other._brain) {
            this->_brain = NULL;
        } else {
            if (this->_brain) {
                delete this->_brain;
            }
            this->_brain = other._brain;
        }
    }
    return *this;
}

Dog::~Dog()
{
    delete _brain;
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
