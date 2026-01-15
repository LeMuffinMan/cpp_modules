
#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _dataBase(other._dataBase) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this == &other)
    return *this;
  _dataBase = other._dataBase;
  return *this;
}

void BitcoinExchange::loadDataBase() {

  std::ifstream file("data.csv");
  if (!file.is_open()) {
    throw std::runtime_error("Error: could not open database file.");
    return;
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    std::string rate;

    if (std::getline(ss, date, ',')) {
      if (std::getline(ss, rate)) {
        _dataBase[date] = std::atof(rate.c_str());
      }
    }
  }
  file.close();
  return;
}

double BitcoinExchange::getRate(std::string date) const {
    try {
        this->isValidDate(date);
    } catch (std::exception &e) {
        throw;
    }

    double rate = -1;
    for (std::map<std::string, double>::const_iterator it = _dataBase.begin(); it != _dataBase.end(); ++it) {
        if (isLowerDate(date, it->second)) {
            rate = it->second;
        } else {
            break;
        }
    }
    if (rate < 0) {
        throw std::runtime_error("Error: No rate found for this date.");
    } else {
        return rate;
    }
}

void BitcoinExchange::printOutput(char *filename) const {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Error: could not open input file.");
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    std::string strvalue;

    if (std::getline(ss, date, ',')) {
      try {
        isValidDate(date);
        if (std::getline(ss, strvalue)) {
            try {
                double value = std::atof(strvalue);
                double rate = getRate(date);
                std::cout << date << " => " << value << " = " << value * rate << std::endl;
            } catch (std::exception &e) {
                std::cout << e.what() << std::endl;
                return;
            }
        }
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
    }
  }
}

void BitcoinExchange::printDataBase() const {
  std::cout << "===-- DataBase --===" << std::endl;
  std::cout << "Size = " << _dataBase.size() << std::endl;

  for (std::map<std::string, double>::const_iterator it = _dataBase.begin();
       it != _dataBase.end(); ++it) {
    std::cout << "Date: " << it->first << " | Rate: " << it->second
              << std::endl;
  }
  std::cout << "==============================================" << std::endl;
}
