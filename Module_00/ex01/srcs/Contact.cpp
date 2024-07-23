#include "Contact.hpp"

// Default initialization
Contact::Contact() {}

// Parameterized constructor definition
Contact::Contact(const std::string& first_name, const std::string& last_name,
				 const std::string& nickname, const std::string& phone_number,
				 const std::string& darkest_secret) :
		_first_name(first_name),
		_last_name(last_name),
		_nickname(nickname),
		_phone_number(phone_number),
		_darkest_secret(darkest_secret) {
}

void get_input(const std::string& prompt, std::string& field) {
	std::cout << prompt << std::endl;
	std::getline(std::cin, field);
	if (std::cin.eof())
		std::exit(0);
}

void Contact::get_new_contact(void) {
	get_input("First Name:", this->first_name);
	get_input("Last Name:", this->last_name);
	get_input("Nickname:", this->nickname);
	get_input("Phone Number:", this->phone_number);
	get_input("Darkest Secret:", this->darkest_secret);
}

bool Contact::check_if_valid(void)
{
	return !(this->first_name.empty() || this->last_name.empty() || this->nickname.empty()
			 || this->phone_number.empty() || this->darkest_secret.empty());
}

const std::string& Contact::getFirstName() const {
	return _first_name;
}

const std::string& Contact::getLastName() const {
	return _last_name;
}

const std::string& Contact::getNickname() const {
	return _nickname;
}

const std::string& Contact::getPhoneNumber() const {
	return _phone_number;
}

const std::string& Contact::getDarkestSecret() const {
	return _darkest_secret;
}