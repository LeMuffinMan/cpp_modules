
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

void RPN::parse(std::string input) {
  std::stringstream ss(input);
  std::string token;

  while (ss >> token) {
    if (token.size() == 1 &&
        (token == "+" || token == "-" || token == "*" || token == "/")) {
      _operators.push(token[0]);
      continue;
    }
    size_t pos = token.find_first_not_of("0123456789");
    if (pos != std::string::npos) {
      std::cout << "Unexpected character: " << token[pos] << std::endl;
    } else {
      long value = strtol(token.c_str(), NULL, 10);
      if (value > 2147483647 || value < -2147483648) {
        std::cout << "Out of int limits" << std::endl;
      }
      _operands.push(value);
    }
  }
  // on veut controler que les deux stacks sont coherentes ici ?
}

void RPN::operate() {
  while (!_operators.empty()) {
    if (_operands.size() < 2) {
      throw std::runtime_error("Error: not enough operands");
    }

    int n1 = _operands.top();
    _operands.pop();

    int n2 = _operands.top();
    _operands.pop();

    if (_operators.empty()) {
      throw std::runtime_error("Error: no operator available");
    }
    char op = _operators.top();
    _operators.pop();
    int res;
    switch (op) {
        case '+':
        res = n1 + n2;
        break;
        case '-':
        res = n1 - n2;
        break;
        case '*':
        res = n1 * n2;
        break;
        case '/':
        res = n1 / n2; // 0 !!!
        break;
        default:
        std::cout << "Unexpected char in operators: " << op << std::endl;
        break;
    }
    if (_operators.empty() && _operands.empty()) {
      std::cout << res << std::endl;
    } else if (_operators.empty()) {
      std::cout << "Missing operator" << std::endl;
    } else if (_operands.empty()) {
      std::cout << "Missing operands" << std::endl;
    } else {
      _operands.push(res);
    }
  }
}
