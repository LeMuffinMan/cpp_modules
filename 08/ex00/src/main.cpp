#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <iostream>
#include <stdexcept>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    //particularites de vec ? dynamic array ? 
    try {
        int res = easyfind(vec, 3);
        std::cout << "Found in vector: " << res << std::endl;
    } catch (const std::exception&) {
        std::cout << "Not found in vector" << std::endl;
    }
    
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
    
    std::deque<int> deq;
    deq.push_back(5);
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
