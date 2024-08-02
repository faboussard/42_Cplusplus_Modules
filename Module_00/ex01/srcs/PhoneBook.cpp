#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(): _contact_count(0){}

void PhoneBook::add(void)
{
	Contact new_contact;

	new_contact.get_new_contact();
	if (!new_contact.check_if_valid())
	{
		std::cout << "Contact could not be saved, one field is empty. try ADD again.\n\n";
		return ;
	}
	else // remplacer fonction par push back. 
	{
		if (_contact_count == 8)
			_contact_count = 0;
		_contact[_contact_count] = new_contact;
		_contact_count++;
	}
}

void PhoneBook::search(void)
{
	std::string index;
	int int_index;

	display_all();
	std::cout << "Select the specific contact to display (enter a number between 1 and 8)\n";
	get_input("Index:", index);
 	int_index = atoi(index.c_str()); 
	display_full_contact(int_index - 1);
}

void PhoneBook::display_contact_element(const std::string& contact)
{
		std::string str;

		if (contact.length() > 9)
		{
        	str = contact.substr(0, 9);
            str.append(".");
		}
		else
			str = contact;
		std::cout << std::setw(10) << str;
}

void PhoneBook::display_all()
{
	std::cout << std::endl;
	std::cout << BGWHITE << BLACK <<"     Index|First name| Last name|  Nickname " << RESET << std::endl;
	for (int i = 0; i < _contact_count; i++)
	{
		display_contact_element(_contact[i].getFirstName());
		std::cout << "|";
		display_contact_element(_contact[i].getLastName());
		std::cout << "|";
		display_contact_element(_contact[i].getNickname());
		std::cout << "|";
		display_contact_element(_contact[i].getPhoneNumber());
		std::cout << "|";
		display_contact_element(_contact[i].getDarkestSecret());
		std::cout << std::endl << "----------+----------+----------+----------" <<std::endl;
	}
}

void PhoneBook::display_full_contact(int index) {
    if (index < 0 || index >= _contact_count) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    Contact contact = _contact[index];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
