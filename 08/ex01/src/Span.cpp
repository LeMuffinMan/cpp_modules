#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) 
    : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}
