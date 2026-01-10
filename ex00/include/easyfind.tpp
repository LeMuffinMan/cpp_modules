#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>
int easyfind(T &container, int value)
{
    typename T::iterator i = container.begin();
    typename T::iterator j = container.end();

    for (int pos = 0; i != j; i++, pos++) {
        if (*i == value) {
            return pos;
        }
    }
    throw std::runtime_error("Value not found in container");
}

#endif
