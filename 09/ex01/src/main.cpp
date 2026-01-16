#include "RPN.hpp"
#include "iostream"

int main (int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.parse(argv[1]);
    rpn.operate();
    return 0;
}
