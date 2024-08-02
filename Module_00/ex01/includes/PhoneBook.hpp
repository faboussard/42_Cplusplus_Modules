#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
#include <iostream>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contact[8];
	int		_contact_count;

public:
	PhoneBook();

	void	add();
	void	search();
	void	exit();
	void	print();
	void operator<<(const Contact &contact);
};

#endif //PHONEBOOK_HPP