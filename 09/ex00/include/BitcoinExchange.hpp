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
  BitcoinExchange(const BitcoinExchange& bc);
  BitcoinExchange& operator=(const BitcoinExchange& bc);

  BitcoinExchange(std::string filename);
  loadFile(std::string filename);
  printDatabase();

  //try catch pour les erreurs
};

#endif
