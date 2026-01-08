#include "Span.hpp"
#include <iostream>

int main()
{
    std::cout << "--- -- Subject test example -- ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;
    std::cout << "--- -- Extra tests -- ---" << std::endl;
    try {
        std::cout << "Attempt to add a 6th number in a spa.n sized 5: " << std::endl;
        sp.addNumber(196);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    sp.printSpan();
    try {
        std::cout << "Shortest spa: " << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << "Longest spa: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--- -- 11000 size Span -- ---" << std::endl;

    Span spa = Span(11000);
    std::cout << std::endl;
    std::cout << "spa with " << spa.getSize() << " number: " << std::endl;
    spa.printSpan();
    try {
        std::cout << "Shortest spa: " << spa.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << "Longest spa: " << spa.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        spa.addNumber(6);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "spa with " << spa.getSize() << " number: " << std::endl;
    spa.printSpan();
    try {
        std::cout << "Shortest spa: " << spa.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << "Longest spa: " << spa.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        spa.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "spa with " << spa.getSize() << " number: " << std::endl;
    spa.printSpan();
    try {
        std::cout << "Shortest spa: " << spa.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << "Longest spa: " << spa.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        spa.addNumber(17);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "spa with " << spa.getSize() << " number: " << std::endl;
    spa.printSpan();
    try {
        std::cout << "Shortest spa: " << spa.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << "Longest spa: " << spa.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        spa.addNumber(9);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "spa with " << spa.getSize() << " number: " << std::endl;
    spa.printSpan();
    try {
        std::cout << "Shortest spa: " << spa.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << "Longest spa: " << spa.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        spa.addNumber(11);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "spa with " << spa.getSize() << " number: " << std::endl;
    spa.printSpan();
    try {
        std::cout << "Shortest spa: " << spa.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << "Longest spa: " << spa.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    //ici boucler pour depasser 10000 ?
    return 0;
}
