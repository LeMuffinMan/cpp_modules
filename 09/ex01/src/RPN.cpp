
#include "RPN.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
    : _operands(other._operands), _operators(other._operators) {}

RPN &RPN::operator=(const RPN &other) {
  if (this == &other)
    return *this;
  _operators = other._operators;
  _operands = other._operands;
  return *this;
}

void RPN::operate(std::string input) {
  std::stringstream ss(input);
  std::string token;

  while (ss >> token) {
    if (token.size() == 1 &&
        (token == "+" || token == "-" || token == "*" || token == "/")) {
      if (_operands.size() < 2) {
        std::cout << "Error" << std::endl;
        return;
      }

      int b = _operands.top();
      _operands.pop();
      int a = _operands.top();
      _operands.pop();
      char op = token[0];

      int result = 0;
      switch (op) {
      case '+':
        result = a + b;
        break;
      case '-':
        result = a - b;
        break;
      case '*':
        result = a * b;
        break;
      case '/':
        if (b == 0) {
          std::cout << "Error" << std::endl;
          return;
        }
        result = a / b;
        break;
      default:
        std::cout << "Error" << std::endl;
        return;
      }

      _operands.push(result);
    } else {
      size_t pos = token.find_first_not_of("0123456789");
      if (pos != std::string::npos) {
        std::cout << "Error" << std::endl;
        return;
      }

      long value = strtol(token.c_str(), NULL, 10);
      if (value > 2147483647 || value < -2147483648) {
        std::cout << "Error" << std::endl;
        return;
      }

      _operands.push(static_cast<int>(value));
    }
  }

  if (_operands.size() != 1) {
    std::cout << "Error" << std::endl;
  } else {
    std::cout << _operands.top() << std::endl;
  }
}
