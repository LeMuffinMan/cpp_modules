#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie 
{
  public :
    void _announce(void) const;
    Zombie(std::string name);
    ~Zombie();
  private :
    std::string _name;

};

#endif
