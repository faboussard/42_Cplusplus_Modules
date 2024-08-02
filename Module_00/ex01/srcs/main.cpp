#include "../includes/PhoneBook.hpp"

int main (void)
{
	std::string command;
	PhoneBook phonebook;
	while (1)
	{
		std::cout << "Enter your command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			break;
	}
    return (0);
}