#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int n);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void addMultipleNumbers();
        void printSpan();
        unsigned int getSize();
};

class SpanFullException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Span is full: cannot add more numbers";
    }
};

class NotEnoughNumbersException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Not enough numbers to calculate span";
    }
};

#endif
