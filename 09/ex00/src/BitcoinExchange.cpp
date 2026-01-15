
#include "BitcoinExchange.hpp"
#include <climits>
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

double BitcoinExchange::getRate(std::string input_date) const {
  double rate = -1;
  for (std::map<std::string, double>::const_iterator it = _dataBase.begin();
       it != _dataBase.end(); ++it) {
    if (input_date > it->first) {
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

bool BitcoinExchange::isValidDate(std::string date) const {
  std::string trimmedDate = date;

  size_t start = trimmedDate.find_first_not_of(" \t\n\r\f\v");
  if (start != std::string::npos) {
    trimmedDate = trimmedDate.substr(start);
  } else {
    return false;
  }

  size_t end = trimmedDate.find_last_not_of(" \t\n\r\f\v");
  if (end != std::string::npos) {
    trimmedDate = trimmedDate.substr(0, end + 1);
  }

  if (trimmedDate.length() != 10) {
    std::cout << trimmedDate.length() << std::endl;
    return false;
  }

  if (trimmedDate[4] != '-' || trimmedDate[7] != '-') {
    return false;
  }

  for (int i = 0; i < 10; i++) {
    if ((i == 4 || i == 7) && trimmedDate[i] == '-')
      continue;
    if (!isdigit(trimmedDate[i])) {
      return false;
    }
  }

  std::string yearStr = trimmedDate.substr(0, 4);
  std::string monthStr = trimmedDate.substr(5, 2);
  std::string dayStr = trimmedDate.substr(8, 2);

  int year;
  int month;
  int day;

  std::istringstream yss(yearStr);
  std::istringstream mss(monthStr);
  std::istringstream dss(dayStr);

  if (!(yss >> year) || !(mss >> month) || !(dss >> day) || year < 2009 ||
      month < 1 || month > 12) {
    return false;
  }
  return this->handleLeapYear(year, month, day);
}

bool BitcoinExchange::handleLeapYear(int year, int month, int day) const {
    static const int normalDays[] = {31, 28, 31, 30, 31, 30,
                                     31, 31, 30, 31, 30, 31};

    bool isLeapYear = false;
    if (year % 400 == 0) {
      isLeapYear = true;
    } else if (year % 100 == 0) {
      isLeapYear = false;
    } else if (year % 4 == 0) {
      isLeapYear = true;
    }

    int maxDays;
    if (month == 2 && isLeapYear) {
      maxDays = 29;
    } else if (month >= 1 && month <= 12) {
      maxDays = normalDays[month - 1];
    } else {
      maxDays = 0;
    }

    if (day > maxDays) {
      return false;
    }

    return true;
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

    if (std::getline(ss, date, '|')) {
      if (!isValidDate(date)) {
        std::cout << "Error: invalid input => " << date << std::endl;
      }
      try {
        if (std::getline(ss, strvalue)) {
          size_t start = strvalue.find_first_not_of(" \t\n\r\f\v");
          if (start != std::string::npos) {
            strvalue.erase(0, start);
          } else {
            strvalue.clear();
            return;
          }
          size_t pos = strvalue.find_first_not_of("0123456789-.");
          if (pos != std::string::npos) {
            std::cout << "Error: value include an invalid character => "
                      << strvalue[pos] << std::endl;
            continue;
          } else if (strvalue[0] == '-') {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
          }
          try {
            double value = std::atof(strvalue.c_str());
            if (value < 0) {
            } else if (value > INT_MAX) {
              std::cout << "Error: too large number" << std::endl;
              continue;
            }
            double rate = getRate(date);
            std::cout << date << " => " << value << " = " << value * rate
                      << std::endl;
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
