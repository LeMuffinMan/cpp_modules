#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    std::cout << std::endl;
    try {
        std::cout << "Span with 1 number: " << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception&) {
        std::cout << "Exception caught" << std::endl;
    }
    std::cout << std::endl;
    try {
        sp.addNumber(6);
        std::cout << "Span with 2 numbers: " << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception&) {
        std::cout << "Exception caught" << std::endl;
    }
    std::cout << std::endl;
    try {
        sp.addNumber(3);
        std::cout << "Span with 3 numbers: " << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception&) {
        std::cout << "Exception caught" << std::endl;
    }
    std::cout << std::endl;
    try {
        sp.addNumber(17);
        std::cout << "Span with 4 numbers: " << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception&) {
        std::cout << "Exception caught" << std::endl;
    }
    std::cout << std::endl;
    try {
        sp.addNumber(9);
        std::cout << "Span with 4 numbers: " << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception&) {
        std::cout << "Exception caught" << std::endl;
    }
    std::cout << std::endl;
    try {
        sp.addNumber(11);
        std::cout << "Span with 5 numbers: " << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception&) {
        std::cout << "Exception caught" << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "Attempt to add a 6th number in a span sized 5: " << std::endl;
        sp.addNumber(196);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception&) {
        std::cout << "Exception caught" << std::endl;
    }
    return 0;
}
