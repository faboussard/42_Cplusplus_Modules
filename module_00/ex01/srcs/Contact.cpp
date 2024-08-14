#include "../includes/Contact.hpp"

Contact::Contact() {}

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

void Contact::setFirstName(std::string new_first_name) {
  _first_name = new_first_name;
}

void Contact::setLastName(std::string new_last_name) {
  _last_name = new_last_name;
}

void Contact::setNickname(std::string new_nickname) {
  _nickname = new_nickname;
}

void Contact::setPhoneNumber(std::string new_phone_number) {
  _phone_number = new_phone_number;
}
void Contact::setDarkestSecret(std::string new_darkest_secret) {
  _darkest_secret = new_darkest_secret;
}

const std::string &Contact::getFirstName() const { return _first_name; }

const std::string &Contact::getLastName() const { return _last_name; }

const std::string &Contact::getNickname() const { return _nickname; }

const std::string &Contact::getPhoneNumber() const { return _phone_number; }

const std::string &Contact::getDarkestSecret() const { return _darkest_secret; }