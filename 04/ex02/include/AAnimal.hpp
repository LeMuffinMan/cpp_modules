#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include "Brain.hpp"

class AAnimal
{
public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal() = 0;
    
    std::string getType() const;
    virtual void makeSound() const;
protected:
    std::string _type;
};

#endif
