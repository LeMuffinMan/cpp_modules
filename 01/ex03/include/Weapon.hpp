#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
  public :
    Weapon(const std::string& tyep);
    const std::string& getType() const;
    void setType(std::string type);
    // ~Weapon();
  private :
    std::string _type;
};

#endif
