#include "ScalarConverter.hpp"
#include <limits>
#include <iostream>

int main (int argc, char **argv)
{
  //uncommented, this line prevent compilation cause constructors / destructors or in private 
  //ScalarConverter converter;

  std::cout << std::numeric_limits<int>::infinity() << std::endl;
  //chez moi infinity en int donne INT_MIN ??

  if (argc != 2 || argv[1][0] == '\0')
  {
    std::cout << "Usage : " << argv[0] << " <value-to-convert>" << std::endl;
    return 1;
  }
  ScalarConverter::convert(argv[1]);
  return 0;
}

