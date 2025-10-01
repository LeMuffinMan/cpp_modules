#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other); 
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();
        
        virtual void makeSound() const = 0;
        std::string getType() const;
    protected:
        std::string type;
};

#endif
