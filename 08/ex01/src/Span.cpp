#include "Span.hpp"
#include <exception>
#include <iostream>
#include <algorithm>
#include <climits>

Span::Span(unsigned int N) : _maxSize(N) {
    std::cout << "Built Span class with _maxSize = " << _maxSize << std::endl;
}

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

void Span::addNumber(int n) {
    if (_numbers.size() < _maxSize) {
        _numbers.push_back(n);
        std::cout << "Added " << n << " to Span" << std::endl;
    } else {
        throw std::exception();
    }
}

unsigned int Span::shortestSpan() {
    if (_numbers.size() < 2) {
        throw std::exception();
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sorted.size(); i++) {
        unsigned int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan() {
    if (_numbers.size() < 2) {
        throw std::exception();
    }

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::min_element(_numbers.begin(), _numbers.end());

    return max - min;
}
