#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : _contact_count(0), _len(0) {}

void PhoneBook::add(void) {
  Contact new_contact;

  new_contact.get_new_contact();
  if (!new_contact.check_if_valid()) {
    std::cout
        << "Contact could not be saved, one field is empty. try ADD again.\n\n";
    return;
  } else {
    if (_contact_count == MAX_CONTACTS) {
      _contact_count = 0;
    }
    _contact[_contact_count] = new_contact;
    if (_contact_count < MAX_CONTACTS)
      _contact_count++;
    if (_len < MAX_CONTACTS)
      _len++;
  }
}

void PhoneBook::search(void) {
  std::string index;
  int int_index;

  display_all();
  std::cout << "Select the specific contact to display (enter the index of the "
               "contact to display)\n";
  get_input("Index:", index);
  int_index = atoi(index.c_str());
  display_full_contact(int_index - 1);
}

void PhoneBook::display_contact_element(const std::string &contact) {
  std::string str;
  if (contact.length() > 9) {
    str = contact.substr(0, 9);
    str.append(".");
  } else
    str = contact;
  std::cout << std::setw(10) << str;
}

void PhoneBook::display_all() {
  std::cout << std::endl;
  std::cout << BGWHITE << BLACK << "     Index|First name| Last name|  Nickname"
            << RESET << std::endl;
  for (int i = 0; i < _len; i++) {
    std::cout << GREEN << std::setw(10) << i + 1 << RESET;
    std::cout << "|";
    display_contact_element(_contact[i].getFirstName());
    std::cout << "|";
    display_contact_element(_contact[i].getLastName());
    std::cout << "|";
    display_contact_element(_contact[i].getNickname());
    std::cout << std::endl << "----------+----------+----------+----------\n\n";
  }
}

void PhoneBook::display_full_contact(int index) {
  if (index < 0 || index >= MAX_CONTACTS) {
    std::cout << RED << "Wrong index\n" << RESET << std::endl;
    return;
  }
  if (index < 0 || index >= _len) {
    std::cout << MAGENTA << "Contact has not be created at this index\n"
              << RESET << std::endl;
    return;
  }
  Contact contact = _contact[index];
  std::cout << "First Name: " << contact.getFirstName() << std::endl;
  std::cout << "Last Name: " << contact.getLastName() << std::endl;
  std::cout << "Nickname: " << contact.getNickname() << std::endl;
  std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
  std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
