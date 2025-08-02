
#include "Harl.hpp"
#include <iostream>

int main (int argc, char **argv)
{
  if (argc != 2) 
  {
    std::cout << "Usage: ./harlFilter [DEBUG | INFO | WARNING | ERROR]" << std::endl;
    return 1;
  }
  // Harl::filter(argv[1]);
  //plutot que harl.filter(...) -> pour appeler la fonction filter sans declarer de Harl
  //--> PARCE QUE LA FONCTION EST EN STATIC

  Harl harl;
  harl.complain(argv[1]);
}
