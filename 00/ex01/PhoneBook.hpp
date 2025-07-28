#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
  public :
    PhoneBook();
    ~PhoneBook();
    // void displayAllContacts();
    void displayContact(int index) const;
    // void destroyContacts();
    void newContact();
  private:
    Contact _contacts[8]; 
    int _index;
};

#endif
