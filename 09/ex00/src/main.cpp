
#include <iostream>
#include "BitcoinExchange.hpp"

int main(char **argv, int argc) {
  if (argc != 2) {
      std::cout << "Usage: ./btc <file_name>" << std::endl;
      return 1;
  }
  if (BitcoinExchange btc = BitcoinExchange(argv[1].to_string()))
      return 1;
}
