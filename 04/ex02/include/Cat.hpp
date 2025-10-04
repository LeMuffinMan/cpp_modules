#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const;
    Brain *getBrain( void ) const;
private:
    Brain* _brain;
};

#endif
