#include "PmergeMe.hpp"
#include <cstdlib>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

void PmergeMe::parse(int argc, char **argv) {
    // The management of errors related to duplicates is left to your
    // discretion
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        for (size_t j = 0; j < arg.length(); j++) {
            if (!isdigit(arg[j])) {
                throw std::runtime_error("Error: Invalid argument '" + arg + "'");
            }
        }

        //overflow du long ?
        long num = strtol(arg.c_str(), NULL, 10);
        if (num <= 0 || num > 2147483647) {
            throw std::runtime_error("Error: Argument '" + arg + "' is out of range");
        }

        _vec.push_back(static_cast<int>(num));
        _deq.push_back(static_cast<int>(num));
    }

    if (_vec.size() < 2) {
        throw std::runtime_error("Error: Need at least 2 numbers to sort");
    }
}

void PmergeMe::run() {
    double vec_start_time = now;
    fordJohnsonSort(_vec);
    this->_vectorTime = now - vec_start_time;

    double deq_start_time = now;
    fordJohnsonSort(_deq);
    this->_dequeTime = now - deq_start_time;
}

void PmergeMe::printContainer() {
    for (int i = 0; i < this->_vec.size(); ++i) {
        //ici throw si les containers ne sont pas identiques
        std::cout << vec[i];
        if (i < this->_vec.size() - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }
}

void PmergeMe::printPerf() {
        std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::vec : " << vecTime << std::endl;
        std::cout << "Time to process a range of " << this->_deq.size() << " elements with std::deq : " << deqTime << std::endl;
}
