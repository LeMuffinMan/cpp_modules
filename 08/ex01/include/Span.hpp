#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
    public:
        Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber();
        void shortesSpan();
        void longestSpan();
        void addMultipleNumbers();
    private:
};

#endif
