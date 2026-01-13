#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {

private:
  std::map<std::string, T> _dataBase;

public:
  BitcoinExchange();
  ~BitcoinExchange();
  // copy ?
  //  assignation ?

  BitcoinExchange(std::string filename);
  loadFile(std::string filename);
  printDatabase();
};

#endif
