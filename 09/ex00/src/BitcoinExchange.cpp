
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
  // try {
  //     this->isValidDate(input_date);
  // } catch (std::exception &e) {
  //     throw;
  // }

  double rate = -1;
  for (std::map<std::string, double>::const_iterator it = _dataBase.begin();
       it != _dataBase.end(); ++it) {
    // std::cout << "input_date = " << input_date << " | it->first = " <<
    // it->first << std::endl;
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
        throw std::runtime_error("Error: bad input (only spaces) => " + date);
    }

    size_t end = trimmedDate.find_last_not_of(" \t\n\r\f\v");
    if (end != std::string::npos) {
        trimmedDate = trimmedDate.substr(0, end + 1);
    }

    if (trimmedDate.length() != 10) {
        std::cout << trimmedDate.length() << std::endl;
        throw std::runtime_error("Error: invalid trimmedDate format (length > 10) => " + trimmedDate);
    }

    if (trimmedDate[4] != '-' || trimmedDate[7] != '-') {
        throw std::runtime_error("Error: invalid trimmedDate format (invalid separator) => " + trimmedDate);
    }

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(trimmedDate[i])) {
            throw std::runtime_error("Error: invalid trimmedDate format (not only digits) => " + trimmedDate);
        }
    }

    std::string yearStr = trimmedDate.substr(0, 4);
    std::string monthStr = trimmedDate.substr(5, 2);
    std::string dayStr = trimmedDate.substr(8, 2);

    int year, month, day;

    std::istringstream yss(yearStr);
    std::istringstream mss(monthStr);
    std::istringstream dss(dayStr);

    //definir des exceptions et ne throw que DateException
    if (!(yss >> year) || !(mss >> month) || !(dss >> day)) {
        throw std::runtime_error("Error: invalid trimmedDate => " + trimmedDate);
    }

    if (year < 2000) {
        throw std::runtime_error("Error: year out of range => " + trimmedDate);
    }

    if (month < 1 || month > 12) {
        throw std::runtime_error("Error: invalid month => " + trimmedDate);
    }
    static const int normalDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
        throw std::runtime_error("Error: bad input => " + trimmedDate);
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

    // std::cout << "Seeking match for input_line : " << line << std::endl;
    if (std::getline(ss, date, '|')) {
      if (!isValidDate(date)) {
        std::cout << "Error: date is not valid" << std::endl;
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
          // std::cout << "strvalue = [" << strvalue << "]" <<  std::endl;
          if (strvalue.find_first_not_of("0123456789-.") != std::string::npos) {
            std::cout << "Error: value is not valid" << std::endl;
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

// void BitcoinExchange::printDataBase() const {
//   std::cout << "===-- DataBase --===" << std::endl;
//   std::cout << "Size = " << _dataBase.size() << std::endl;

//   for (std::map<std::string, double>::const_iterator it =
//   _dataBase.begin();
//        it != _dataBase.end(); ++it) {
//     std::cout << "Date: " << it->first << " | Rate: " << it->second
//               << std::endl;
//   }
//   std::cout << "==============================================" <<
//   std::endl;
// }
