#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(): _contact_count(0){}

void PhoneBook::add(void)
{
	Contact new_contact;

	new_contact.get_new_contact();
	//if (!new_contact.check_if_valid())

}

