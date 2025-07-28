
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>

bool isNumber(const std::string& s)
{
    for (size_t i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
            return false;
    return !s.empty();
}

int main ()
{
  std::string input;
  PhoneBook myPhoneBook;
  int index;
  std::string sep(50, '=');

  while (1)
  {
    std::cout << std::endl;
    std::cout << sep << std::endl;
    std::cout << "Usage :" << std::endl;
    std::cout << "ADD : save a new contact" << std::endl;
    std::cout << "SEARCH : display a specific contact" << std::endl;
    std::cout << "EXIT : quit program" << std::endl << std::endl;
    if (!std::getline(std::cin, input))
    {
        std::cout << "EOF : exiting ..." << std::endl;
        return (1);
    }
    if (input == "ADD")
    {
        std::cout << "NEW CONTACT" << std::endl;
        myPhoneBook.newContact();
    }
    else if (input == "SEARCH")
    {
        myPhoneBook.displayContact(-1);
        index = -1;
        while (index < 0)
        {
          std::cout << "index : ";
          if (!std::getline(std::cin, input))
          {
              std::cout << "EOF : exiting ..." << std::endl;
              return (1);
          }
          try
          {
            if (!isNumber(input))
              throw std::exception();
            index = atoi(input.c_str());
          }
          catch (const std::exception& e)
          {
              std::cout << "Invalid input" << std::endl;
          }      
          if (index > 8 || index < 0)
          {
            std::cout << "Incorrect index : " << index << std::endl;
            index = -1;
          }
        }
        myPhoneBook.displayContact(index);
        index = 0;
    }
    else if (input == "EXIT")
    {
        break;
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
    }
  }
  return (0);
}
