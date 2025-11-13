#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
int easyfind(T &container, int value)
{
    typename T::iterator i = container.begin();
    typename T::iterator j = container.end();
    
    for (; i != j; i++) {
        if (*i == value) {
            return *i;
        }
    }
    throw std::exception();
}

#endif 
