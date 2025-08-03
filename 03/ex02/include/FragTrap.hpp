#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name); // Default constructor
    FragTrap(const FragTrap& other); // Copy constructor
    FragTrap& operator=(const FragTrap& other); // Copy assignment
    ~FragTrap(); // Destructor

    void highFiveGuys(void);
};

#endif
