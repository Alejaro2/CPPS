#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>

class PhoneBook {
private:
  Contact _contacts[8];
  int _index;
  int _count;

  std::string _getInput(std::string prompt, int mode) const;
  std::string _format(std::string prompt)const;

public:
  PhoneBook();
  ~PhoneBook();

  void addContact();
  void searchContact()const;
};

#endif
