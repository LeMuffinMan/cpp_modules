#include "ICharacter.hpp"

class Cure : public AMateria
{
  public: 
    Cure();
    virtual ~Cure() throw(); //pas clair le throw
    virtual Cure* clone() const;
    virtual void use(ICharacter& target);
};
