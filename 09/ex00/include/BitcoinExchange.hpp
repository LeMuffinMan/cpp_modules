#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {

private:
  std::map<std::string, double> _dataBase;
  // BitcoinExchange(std::string filename);
  // loadInput(std::string filename);

public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &bc);
  BitcoinExchange &operator=(const BitcoinExchange &bc);

  void loadDataBase();
  void printDataBase() const;
};

#endif
