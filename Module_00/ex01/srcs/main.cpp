#include "../includes/PhoneBook.hpp"

int main(void) {
  std::string command;
  PhoneBook phonebook;
  while (1) {
    std::cout << "Welcome to Phonebook ! ";
    if (get_input("Enter your command: ADD, SEARCH OR EXIT\n", command) == 1)
      return (1);
    if (command == "ADD")
      phonebook.add();
    else if (command == "SEARCH")
      phonebook.search();
    else if (command == "EXIT")
      break;
  }
  return (0);
}