
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : _index(0) {

}
 
PhoneBook::~PhoneBook()
{

}

std::string formatString(const std::string str)
{
  std::string res;
  res = str;
  if (res.length() > 10)
      return res.substr(0, 9) + ".";
  else
      return res;
}

void PhoneBook::displayContact(int index) const
{
  std::string sep(50, '-');
  if (index <= 0)
  {
    std::cout << std::endl;
    std::cout << "| Index | First Name | Last Name  | Nickname   |" << std::endl;
    std::cout << sep << std::endl;
    for (int i = 0; i < _index && i < 8; i++)
    {
        std::cout << "|   " << i + 1 << "   | ";

        std::string first = _contacts[i].getFirstName();
        std::string last = _contacts[i].getLastName();
        std::string nick = _contacts[i].getNickname();

        std::cout << std::setw(10) << formatString(first) << " | ";
        std::cout << std::setw(10) << formatString(last) << " | ";
        std::cout << std::setw(10) << formatString(nick) << " |" << std::endl;
    }
  }
  else if (index > PhoneBook::_index) 
  {
    std::cout << "Contact #" << index << " does not exists" << std::endl;
  }
  else
  {
    std::cout << std::endl;
    std::cout << "First Name : " <<  _contacts[index - 1].getFirstName() << std::endl;
    std::cout << "Last Name : " << _contacts[index - 1].getLastName() << std::endl;
    std::cout << "Nickname : " << _contacts[index - 1].getNickname() << std::endl;
    std::cout << "Phone Number : " << _contacts[index - 1].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << _contacts[index - 1].getDarkestSecret() << std::endl;
  }
}

void PhoneBook::newContact()
{
    _contacts[_index].fillContact();
    _index++;
    if (_index == 8)
      _index = 0;
}

