#include "ScalarConverter.hpp"
#include <iostream>

int main (int argc, char **argv)
{
  //uncommented, this line prevent compilation cause constructors / destructors or in private 
  //ScalarConverter converter;

  if (argc != 2 || argv[1][0] == '\0')
  {
    std::cout << "Usage : " << argv[0] << " <value-to-convert>" << std::endl;
    return 1;
  }
  ScalarConverter::convert(argv[1]);
  // ScalarConverter::convert("");
  // ScalarConverter::convert("0");
  // ScalarConverter::convert("42");
  // ScalarConverter::convert("-42");
  // ScalarConverter::convert("'A'"); 
  // ScalarConverter::convert("'A'"); 
  // ScalarConverter::convert("0.0f");
  // ScalarConverter::convert("-4.2f");
  // ScalarConverter::convert("4.2f");
  // ScalarConverter::convert("0.0");
  // ScalarConverter::convert("4.2");
  // ScalarConverter::convert("-4.2");
  // ScalarConverter::convert("nan");
  // ScalarConverter::convert("-inff");
  // ScalarConverter::convert("+inff");
  // ScalarConverter::convert("-inf");
  // ScalarConverter::convert("+inf");

  return 0;
}
