#ifndef ARRAYTEMPLATE_HPP
#define ARRAYTEMPLATE_HPP

#include <cstddef>

template <typename T>
Array<T>::Array() : _data(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(0), _size(n) {
    if (n > 0) {
        _data = new T[n](); 
    }
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _data(0), _size(other._size) {
    if (_size > 0) {
        _data = new T[_size];
        for (size_t i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] _data;        
        _size = other._size;

        if (_size > 0) {
            _data = new T[_size];
            for (size_t i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        } else {
            _data = 0;
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Error : index out of limits");
    }
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Error : index out of limits");
    }
    return _data[index];
}

template <typename T>
size_t Array<T>::size() const {
    return _size;
}

#endif


