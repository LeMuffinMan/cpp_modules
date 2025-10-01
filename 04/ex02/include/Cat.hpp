#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "AAnimal.hpp"

class Cat : public AAnimal
{
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const;
private:
    std::string _type;
};

#endif
