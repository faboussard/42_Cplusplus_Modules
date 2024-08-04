#include "../includes/Contact.hpp"

Contact::Contact() {
} // on a besoin de ca pour que dans la methode Phonebook::add on puisse
  // declarer Contact newcontact, sans avoir a definir toutes les variables
  // first name etc.

// Puis on fait linitialisation pour pouvoir utiliser les first name etc dans la
// fonction get new contact par exemple.
Contact::Contact(const std::string &a, const std::string &b,
                 const std::string &c, const std::string &d,
                 const std::string &e)
    : _first_name(a), _last_name(b), _nickname(c), _phone_number(d),
      _darkest_secret(e) {}

Contact::~Contact(void) {};

void Contact::get_new_contact(void) {
  get_input("First Name:", this->_first_name);
  get_input("Last Name:", this->_last_name);
  get_input("Nickname:", this->_nickname);
  get_input("Phone Number:", this->_phone_number);
  get_input("Darkest Secret:", this->_darkest_secret);
}

bool Contact::check_if_valid(void) {
  return !(this->_first_name.empty() || this->_last_name.empty() ||
           this->_nickname.empty() || this->_phone_number.empty() ||
           this->_darkest_secret.empty());
}

const std::string &Contact::getFirstName() const { return _first_name; }

const std::string &Contact::getLastName() const { return _last_name; }

const std::string &Contact::getNickname() const { return _nickname; }

const std::string &Contact::getPhoneNumber() const { return _phone_number; }

const std::string &Contact::getDarkestSecret() const { return _darkest_secret; }