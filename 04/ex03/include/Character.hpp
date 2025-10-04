#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "ChainedList.hpp"
#include <string>

class Character : public ICharacter {
  private:
      std::string _name;
      AMateria* _inventory[4];
      ChainedList _floor; //tout le monde devrait avoir le meme floor ?
      
  public:
      Character(std::string name);
      Character(const Character& other);
      Character& operator=(const Character& other);
      ~Character();
      
      std::string const & getName() const;
      AMateria* getMateria(int idx) const;
      void equip(AMateria* m);
      void unequip(int idx);
      void use(int idx, ICharacter& target);
      void printInventory() const;
};

#endif
