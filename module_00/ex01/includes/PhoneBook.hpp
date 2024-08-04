#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Utils.hpp"
#include <cstdlib>
#include <iomanip>

#define MAX_CONTACTS 8
/*
le constructeur peut etre cree vide ( on le fait souvent comme ca par defaut) ou
bien avec des objets dedans. pour contact, on a les deux options, et on part du
postulat qu un contact aura les first names, etcc decides. ici pour phonebook ce
nest pas necessaire dans notre exemple.
*/
class PhoneBook {
private:
  Contact _contact[8];
  int _contact_count;
  int _len;

public:
  PhoneBook(void);
  ~PhoneBook(void);
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