#include "ScalarConverter.hpp"
#include <limits>
#include <iostream>

int main (int argc, char **argv)
{
  //uncommented, this line prevent compilation cause constructors / destructors are in private 
  //ScalarConverter converter;

  // std::cout << std::numeric_limits<int>::infinity() << std::endl;
  // i used this line to determine how to handle +inf and -inf in int
  // Depending of compiler, it results either INT_MIN or 0

  if (argc != 2 || argv[1][0] == '\0')
  {
    std::cout << "Usage : " << argv[0] << " <value-to-convert>" << std::endl;
    return 1;
  }
  ScalarConverter::convert(argv[1]);
  return 0;
}

