#ifndef WHATEVER_HPP
#define WHATEVER_HPP

//pas utiliser les ref pour prouver qu'on renvoie b et pas a si egaux ?


template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const &min(T const &a, T const &b) {
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T const &max(T const &a, T const &b) {
    if (a > b)
        return a;
    else
        return b;
}

#endif
