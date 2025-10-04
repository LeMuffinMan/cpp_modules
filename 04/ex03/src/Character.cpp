#include "Character.hpp"
#include <iostream>

Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < 4; i++) _inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;

        for (int i = 0; i < 4; i++) {
            if (_inventory[i]) {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
        }
        
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i]) delete _inventory[i];
    }
}

AMateria* Character::getMateria(int idx) const {
    if (idx >= 0 && idx < 4)
        return _inventory[idx];
    return NULL;
}

std::string const & Character::getName() const { return _name; }

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
    delete m;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        _floor.add(_inventory[idx]);
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        _inventory[idx]->use(target);
    } else {
        std::cout << _name << " action failed : there is no materia on slot " << idx << std::endl;
    }
}

void Character::printInventory() const {
    std::cout << "Inventory of " << _name << ":\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "Slot " << i << ": " << _inventory[i] 
                  << (_inventory[i] ? " [" + _inventory[i]->getType() + "]" : " empty") 
                  << std::endl;
    }
    std::cout << "Floor :";
    _floor.display();
}
