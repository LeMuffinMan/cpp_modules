#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> 
#include <cstddef> 
// #include "Array.cpp" 

template <typename T>
class Array {
private:
    T* _data;        
    size_t _size;   

public:
    Array();                  
    Array(unsigned int n);    
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t size() const;
};


#endif
