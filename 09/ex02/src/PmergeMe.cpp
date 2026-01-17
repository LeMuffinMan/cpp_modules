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
    //run avec vec
    Solver solve(this->_vec);

    solve.sort();
    std::vector<int> res = solve.getResult();
    double vecTime = solve.getExecutionTime();

    //run avec deq
    Solver solve(this->_deq);

    solve.sort();
    std::deque<int> res = solve.getResult();
    double deqTime = solve.getExecutionTime();

    //time :
    // start au parsing ?
    // start -> sort = time to set
    // sort -> sorted vec = time to sort vec
    // sort -> sorted deque = time to sort deque
    // vecTime = time to set + time to sort vec
    // DeqTime = time to set + time to sort deq - time to sort deque
    //
    std::cout << "Before: ";
    for (int i = 0; i < this->_vec.size(); ++i) {
        std::cout << vec[i];
        if (i < this->_vec.size() - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }

    std::cout << "After: ";
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }
    std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::vec : " << vecTime << std::endl;
    std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::deq : " << deqTime << std::endl;
}
