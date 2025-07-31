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

std::string Contact::getDarkestSecret() const
{
  return _darkestSecret;
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
