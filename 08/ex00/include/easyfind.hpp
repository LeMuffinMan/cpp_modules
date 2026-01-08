#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
int easyfind(T &container, int value)
{
    //declaring an iterator on any type
    typename T::iterator i = container.begin();
    //end() point AFTER the last element
    typename T::iterator j = container.end();

    for (; i != j; i++) {
        if (*i == value) {
            return *i;
        }
    }
    throw std::exception();
}

#endif
