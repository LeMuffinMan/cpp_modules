#include "Contact.hpp"
#include <iostream>

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

void Contact::setField(std::string name, std::string &field)
{
  std::cout << name;
  while (true)
  {
    if (!std::getline(std::cin, field)) 
    {
      std::cout << "\nInput interrupted. Exiting ..." << std::endl;
      field = "";  
      break;
    }
    if (field.empty())
    {
      std::cout << "Empty input is incorrect, please try again: ";
      continue;
    }
    if (field.length() >= 10)
      field[9] = '.';

    break;
  }
}


void Contact::fillContact()
{
    setField("First Name: ", this->_firstName);
    setField("Last Name: ", this->_lastName);
    setField("Nickname: ", this->_nickname);
    setField("Phone Number: ", this->_phoneNumber);
    setField("Darkest Secret: ", this->_darkestSecret);
}
