#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {

private:
  std::map<std::string, double> _dataBase;

public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &bc);
  BitcoinExchange &operator=(const BitcoinExchange &bc);

  void loadDataBase();
  void loadInput(char* filename);
  void printDataBase() const;
};

#endif
