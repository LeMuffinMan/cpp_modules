#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
  std::stack<int> _operands;
  std::stack<char> _operators;

public:
  RPN();
  ~RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);

  void parse(std::string input);
  void operate();
};

#endif
