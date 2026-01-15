#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {

private:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& bc);
  BitcoinExchange& operator=(const BitcoinExchange& bc);

  std::map<std::string, double> _dataBase;
  BitcoinExchange(std::string filename);
  loadInput(std::string filename);
  printDatabase();

public:
  //try catch pour les erreurs
};

#endif
