#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(): _contact_count(0){}

void PhoneBook::add(void)
{
	Contact new_contact;

	new_contact.get_new_contact();
	if (!new_contact.check_if_valid())
		return ;
	else
	{
		if (_contact_count == 8)
			_contact_count = 0;
		_contact[_contact_count] = new_contact;
		_contact_count++;
	}
}

void PhoneBook::search(void)
{
	for (int i = 0; i < _contact_count; i++)
	{
		display_contact(_contact[i].getFirstName());
		display_contact(_contact[i].getLastName());
		display_contact(_contact[i].getNickname());
		display_contact(_contact[i].getPhoneNumber());
		display_contact(_contact[i].getDarkestSecret());
	}
}

void PhoneBook::display_contact(const std::string& contact)
{
		std::string str;

		if (contact.length() > 9)
		{
        	str = contact.substr(0, 9);
            str.append(".");
		}
		else
			str = contact;
		std::cout << str;
}

