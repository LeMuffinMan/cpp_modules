#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter 
{
  public: 
    Character(std::string name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    virtual std::string const & getName() const ;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    void printInventory() const;
    AMateria* getMateria(int idx) const;
  private: 
    std::string _name;
    AMateria* _inventory[4];
    // std::vector<AMateria*> _floor;
};

#endif
