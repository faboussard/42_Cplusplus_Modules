#include "../includes/PhoneBook.hpp"

int PhoneBook::_index = 0;

std::string Phonebook::get_action(void) {
	std::string input;

	std::cout << "Enter your command: ";
	std::getline(std::cin, input);
	return (input);
}

//void Phonebook::operator<<(const Contact &contact) {
//	this->add(contact);
//}
//
//book << contact << contact2;
//
//book.add(contact);