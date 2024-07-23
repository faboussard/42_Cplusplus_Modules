#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
#include <iostream>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contact[8];
	int		_contactCount;
	int		_index;
	void	_printRows(const std::string index,
					   const std::string firstName,
					   const std::string lastName,
					   const std::string nickname);

public:
	PhoneBook();

	void	add();
	void	search();
	void	exit();
	void	print(void);
};

#endif //PHONEBOOK_HPP