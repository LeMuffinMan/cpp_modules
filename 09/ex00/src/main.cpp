
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./btc <file_name>" << std::endl;
    return 1;
  }
  BitcoinExchange btc;
  try {
      btc.loadDataBase();
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
    return 1;
  }
  (void)argv;
  btc.printDataBase();
  return 0;
}
