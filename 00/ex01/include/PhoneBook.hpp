#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
  public :
    PhoneBook();
    ~PhoneBook();
    void displayContact(int index) const;
    void newContact();
  private:
    Contact _contacts[8]; 
    int _index;
};

#endif
