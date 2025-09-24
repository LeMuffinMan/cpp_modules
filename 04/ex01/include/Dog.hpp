#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "AAnimal.hpp"

class Dog : public AAnimal
{
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();
    
    void makeSound() const;
private:
    std::string _type;
};

#endif
