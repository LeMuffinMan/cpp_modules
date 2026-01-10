#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
// #include <array>
// #include <set>
#include <iostream>
#include <stdexcept>

int main() {
    //Vectors are dynamic arrays in contiguous memory :
    // access by index -> O(1)
    // insertion / delete -> end = O(1) / or O(n)
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    try {
        int res = easyfind(vec, 3);
        std::cout << "Found in vector: " << res << std::endl;
    } catch (const std::exception&) {
        std::cout << "Not found in vector" << std::endl;
    }

    //non contiguous : collection of nodes pointing to each other, spread in the memory
    //insertion / deletion anywhere : O(1) IF we have an iterator
    // impossible to access by index
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(42);

    //particularites de list ? double chained list
    try {
        int res = easyfind(lst, 42);
        std::cout << "Found in list: " << res << std::endl;
    } catch (const std::exception&) {
        std::cout << "Not found in list" << std::endl;
    }

    //deque : double ended queue :
    // -> memory blocks, but not contiguous
    // Access -> O(1) by index
    // insert / delete -> end or begin : O(1), or O(n)
    // efficient growth if increase from begining or end
    std::deque<int> deq;
    deq.push_back(5);
    //push_front ferait aussi O(1)
    deq.push_back(6);
    deq.push_back(7);

    //particularites du deque ? double ended queue
    try {
        int res = easyfind(deq, 8);
        std::cout << "Found in deque: " << res << std::endl;
    } catch (const std::exception&) {
        std::cout << "Not found in deque" << std::endl;
    }

    return 0;
}
