#ifndef ICE
#define ICE

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
  public: 
    Ice();
    virtual ~Ice();
    virtual Ice* clone() const;
    virtual void use(ICharacter& target);
};

#endif 
