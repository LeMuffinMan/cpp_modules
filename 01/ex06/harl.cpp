
#include "Harl.hpp"
#include <iostream>

void Harl::debug() {
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
}

void Harl::info() {
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money.\n";
}

void Harl::warning() {
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free.\n";
}

void Harl::error() {
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*functions[])() = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
  };
  for (int i = 0; i < 4; ++i) {
    if (levels[i] == level) {
      (this->*functions[i])();
      return;
    }
  }
  std::cout << "Unknown level" << std::endl;
}
