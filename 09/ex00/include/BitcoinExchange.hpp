#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {

private:
  std::map<std::string, double> _dataBase;
  double getRate(std::string date) const;
  bool isValidDate(std::string date) const;
  bool handleLeapYear(int year, int month, int day) const;

public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);

  void loadDataBase();
  void processInput(char* filename) const;
};

#endif
