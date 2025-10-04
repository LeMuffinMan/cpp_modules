#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat() : Animal(), _brain(NULL)
{
    _type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	this->_type = other._type;
	if (other._brain) {
	    this->_brain = new Brain(*(other._brain));
	} else {
        this->_brain = new Brain;
	}
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type; 
        if (!other._brain) {
            if (this->_brain) {
                delete this->_brain;
            }
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

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

Brain *Cat::getBrain( void ) const
{
	return (this->_brain);
}
