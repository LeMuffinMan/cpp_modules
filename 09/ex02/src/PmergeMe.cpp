#include "PmergeMe.hpp"
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <iostream>

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

        for (size_t i = 0; i < _vec.size(); ++i) {
            if (num == _vec[i]) {
                std::ostringstream oss;
                oss << "Error: Duplicated number: " << num;
                throw std::runtime_error(oss.str());            }
        }

        _vec.push_back(static_cast<int>(num));
        _deq.push_back(static_cast<int>(num));
    }

    if (_vec.size() < 2) {
        throw std::runtime_error("Error: Need at least 2 numbers to sort");
    }
}

void PmergeMe::run() {
    // double vec_start_time = now;
    this->fordJohnsonSort(_vec);
    // this->_vectorTime = now - vec_start_time;

    // double deq_start_time = now;
    // this->fordJohnsonSort(_deq);
    // this->_dequeTime = now - deq_start_time;

    //ici comparer les deux conteneurs et throw ?
}

template <typename Container>
void PmergeMe::swapPairs(Container &container) {
    for (size_t i = 0; i < container.size(); i += 2) {
        if (i + 1 == container.size())
            break;
        if (container[i] > container[i + 1]) {
            std::swap(container[i + 1], container[i]);
        }
    }
}

template <typename Container>
void PmergeMe::sortPairs(Container &container) {
    size_t pairCount = container.size() / 2;
    for (size_t i = 0; i < pairCount - 1; ++i) {
        for (size_t j = i + 1; j < pairCount; ++j) {
            size_t idx_i = i * 2;
            size_t idx_j = j * 2;

            if (container[idx_i + 1] > container[idx_j + 1]) {
                std::swap(container[idx_i], container[idx_j]);
                std::swap(container[idx_i + 1], container[idx_j + 1]);
            }
        }
    }
}

template <typename Container>
void PmergeMe::buildMainChain(Container &container, Container &mainChain, Container &pend) {

    mainChain.push_back(container[0]);
    for (size_t i = 0; i < container.size() / 2; ++i) {
        size_t idx = i * 2;
        mainChain.push_back(container[idx + 1]);
        if (i > 0)
            pend.push_back(container[idx]);
    }

    if (container.size() % 2 == 1)
        pend.push_back(container[container.size() - 1]);

    std::cout << "mainChain: ";
    for (size_t i = 0; i < mainChain.size(); ++i) {
        std::cout << mainChain[i] << ' ';
    }

    std::cout << std::endl << "pend: ";
    for (size_t i = 0; i < pend.size(); ++i) {
        std::cout << pend[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::generateJacobsthal(size_t n, Container &jacobsthal) {

    if (n == 0) return;

    jacobsthal.push_back(0);
    if (n == 1) return;

    jacobsthal.push_back(1);

    while (true) {
        size_t size = jacobsthal.size();
        size_t next = jacobsthal[size - 1] + 2 * jacobsthal[size - 2];

        if (next >= n)
            break;

        jacobsthal.push_back(next);
    }
}

template <typename Container>
void PmergeMe::createInsertionOrder(size_t pendSize, Container &order) {
    Container jacobsthal;
    generateJacobsthal(pendSize, jacobsthal);
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t current = jacobsthal[i];
        size_t previous = jacobsthal[i - 1];

        for (size_t j = current; j > previous; --j) {
            if (j < pendSize)
                order.push_back(j);
        }
    }

    size_t lastJacob = 0;
    if (jacobsthal.empty()) {
        lastJacob = jacobsthal.back();
    }
    for (size_t i = lastJacob + 1; i < pendSize; ++i) {
        order.push_back(i);
    }
    std::cout << "Order: ";
    for (size_t i = 0; i < order.size(); ++i) {
        std::cout << order[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container &container) {
    //lancer chrono ici ?

    swapPairs(container);
    std::cout << "Container after swaping pairs: ";
    this->printContainer();
    sortPairs(container);
    std::cout << "Container after sorting pairs: ";
    this->printContainer();
    Container pend;
    Container mainChain;
    this->buildMainChain(container, mainChain, pend);
    Container order;
    this->createInsertionOrder(pend.size(), order);

}

void PmergeMe::printContainer() {
    for (size_t i = 0; i < this->_vec.size(); ++i) {
        //ici throw si les containers ne sont pas identiques
        std::cout << _vec[i];
        if (i < this->_vec.size() - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }
}

void PmergeMe::printPerf() {
        std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::vec : " << this->_vecTime << std::endl;
        std::cout << "Time to process a range of " << this->_deq.size() << " elements with std::deq : " << this->_deqTime << std::endl;
}
