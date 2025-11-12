#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime> 

Base* generate(void)
{
    std::srand(time(0));
    int random = std::rand() % 3;

    switch (random)
    {
        case 0:
            std::cout << "Generated A" << std::endl;
            return new A;
        case 1:
            std::cout << "Generated B" << std::endl;
            return new B;
        default:
            std::cout << "Generated C" << std::endl;
            return new C;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "dynamic_cast was successfull using cast : A*" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "dynamic_cast was successfull using cast : B*" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "dynamic_cast was successfull using cast : C*" << std::endl;
    else
        std::cout << "dynamic_cast failed using A* B* C* casts" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "dynamic_cast as A& success" << std::endl;
        return;
    } catch (...) {
    }

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "dynamic_cast as B& success" << std::endl;
        return;
    } catch (...) {
    }

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "dynamic_cast as C& success" << std::endl;
        return;
    } catch (...) {
    }
    std::cout << "dynamic_cast failed using A& B& C& casts" << std::endl;
}

int main()
{
    Base* base = generate();

    identify(base);
    identify(*base);

    delete base;
    return 0;
}
