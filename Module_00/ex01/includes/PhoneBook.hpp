#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
# include <iomanip>

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
	void	display_contact(const std::string& contact);
	
	void operator<<(const Contact &contact);
	//permet dafficher contact dune maniere difference grace a la surchage doperateur 
};

#endif //PHONEBOOK_HPP