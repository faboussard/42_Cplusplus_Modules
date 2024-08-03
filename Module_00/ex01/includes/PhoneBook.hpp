#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Utils.hpp"
#include <cstdlib>
#include <iomanip>

#define MAX_CONTACTS 2

class PhoneBook {
private:
  Contact _contact[8];
  int _contact_count;
  int _len;

public:
  PhoneBook();

  void add();
  void search();
  void exit();
  void print();
  void display_all();
  void display_contact_element(const std::string &contact);
  void display_full_contact(int index);

  void operator<<(const Contact &contact);
};

#endif // PHONEBOOK_HPP