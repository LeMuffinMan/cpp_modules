#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber();
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void addMultipleNumbers();
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
};

#endif
