#include <iostream>
#include "iter.hpp"

void printInt(const int& x) {
  std::cout << x << " ";
}

void printString(const std::string& x) {
  std::cout << x << " ";
}

void doubleValue(int& x) {
  x *= 2;
}

void printCharFromInt(const int& x) {
    std::cout << static_cast<char>(x);
}

template<typename T>
void printAny(const T& x) {
    std::cout << x << " ";
}

int main() {
    int numbers[] = {65, 66, 67, 68, 69};
    std::string words[] = {"hello", "world"};

    iter(numbers, 5, printInt);
    std::cout << std::endl;

    iter(words, 2, printString);
    std::cout << std::endl;

    iter(numbers, 5, doubleValue);

    iter(numbers, 5, printInt);
    std::cout << std::endl;

    std::cout << std::endl;

    int fortytwo[] = {26, 25};
    iter(fortytwo, 2, printInt);
    std::cout << std::endl;
    iter(fortytwo, 2, doubleValue);
    iter(fortytwo, 2, printInt);
    std::cout << std::endl;
    iter(fortytwo, 2, printCharFromInt);
    std::cout << std::endl;

    std::cout << std::endl;
    float floats[] = {1.1f, 2.2f, 3.3f};
    iter(floats, 3, printAny<float>);
    std::cout << std::endl;

    return 0;
}
