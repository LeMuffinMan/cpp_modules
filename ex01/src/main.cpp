#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

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
    std::cout << "--- -- Large test (10,000 numbers) -- ---" << std::endl;
    {
        Span largeSpan(10000);

        for (int i = 0; i < 10000; ++i) {
            largeSpan.addNumber(i * 3);
        }

        std::cout << "10,000 numbers added successfully." << std::endl;
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- -- Very large test (100,000 numbers) -- ---" << std::endl;
    {
        Span veryLargeSpan(100000);

        for (int i = 0; i < 100000; ++i) {
            veryLargeSpan.addNumber(i * 2);
        }

        std::cout << "100,000 numbers added successfully." << std::endl;
        std::cout << "Shortest span: " << veryLargeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << veryLargeSpan.longestSpan() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- -- Random numbers test -- ---" << std::endl;
    {
        Span randomSpan(50000);
        std::srand(static_cast<unsigned int>(std::time(NULL)));

        for (int i = 0; i < 50000; ++i) {
            randomSpan.addNumber(std::rand() % 1000000);
        }

        std::cout << "50,000 random numbers added successfully." << std::endl;
        std::cout << "Shortest span: " << randomSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << randomSpan.longestSpan() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- -- Edge cases test -- ---" << std::endl;
    {
        Span twoNumbers(2);
        twoNumbers.addNumber(10);
        twoNumbers.addNumber(20);
        std::cout << "Two numbers [10, 20]:" << std::endl;
        std::cout << "Shortest span: " << twoNumbers.shortestSpan() << std::endl;
        std::cout << "Longest span: " << twoNumbers.longestSpan() << std::endl;
        std::cout << std::endl;

        Span negativeSpan(5);
        negativeSpan.addNumber(-100);
        negativeSpan.addNumber(-50);
        negativeSpan.addNumber(0);
        negativeSpan.addNumber(50);
        negativeSpan.addNumber(100);
        std::cout << "Numbers with negatives [-100, -50, 0, 50, 100]:" << std::endl;
        std::cout << "Shortest span: " << negativeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << negativeSpan.longestSpan() << std::endl;
        std::cout << std::endl;

        Span duplicateSpan(5);
        duplicateSpan.addNumber(5);
        duplicateSpan.addNumber(5);
        duplicateSpan.addNumber(10);
        duplicateSpan.addNumber(10);
        duplicateSpan.addNumber(15);
        std::cout << "Numbers with duplicates [5, 5, 10, 10, 15]:" << std::endl;
        std::cout << "Shortest span: " << duplicateSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << duplicateSpan.longestSpan() << std::endl;
    }

    return 0;
}
