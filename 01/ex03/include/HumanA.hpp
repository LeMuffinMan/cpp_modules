#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
  public :
    HumanA(std::string, Weapon& weapon);
    void attack();
  private :
    std::string name;
    Weapon& weapon;
};

#endif
