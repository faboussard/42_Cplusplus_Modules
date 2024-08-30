#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Utils.hpp"
#include <iostream>
#include <string>

class Contact {

private:
  std::string _first_name;
  std::string _last_name;
  std::string _nickname;
  std::string _phone_number;
  std::string _darkest_secret;

public:
  Contact(void);
  ~Contact(void);
  Contact(const std::string &a, const std::string &b, const std::string &c,
          const std::string &d, const std::string &e);

  void setFirstName(std::string new_first_name);
  void setLastName(std::string new_last_name);
  void setNickname(std::string new_nickname);
  void setPhoneNumber(std::string new_phone_number);
  void setDarkestSecret(std::string new_darkest_secret);

  const std::string &getFirstName(void) const;
  const std::string &getLastName(void) const;
  const std::string &getNickname(void) const;
  const std::string &getPhoneNumber(void) const;
  const std::string &getDarkestSecret(void) const;
  void get_new_contact(void);
  bool check_if_valid(void);
};

#endif // CONTACT_HPP
