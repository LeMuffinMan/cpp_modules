#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other); 
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();
    
    void makeSound() const;
private:
};

#endif
