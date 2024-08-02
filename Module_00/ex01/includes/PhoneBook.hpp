#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"
#include "Utils.hpp"

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
	void	display_all();
	void	display_contact_element(const std::string& contact);
	void 	display_full_contact(int index);

	void operator<<(const Contact &contact);
	//permet dafficher contact dune maniere difference grace a la surchage doperateur 
};

#endif //PHONEBOOK_HPP