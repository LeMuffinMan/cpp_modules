#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

AMateria::~AMateria() {}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "use " << _type << "materia" << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
}
