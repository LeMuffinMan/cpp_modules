
#include "Character.hpp"

Character::Character(std::string const & name) : _name(name) {}

Character::~Character() {}

std::string& Character::getName() {
  return _name;
}
