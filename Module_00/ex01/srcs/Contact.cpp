#include "../includes/Contact.hpp"


// Default initialization
Contact::Contact() {}

// Parameterized constructor definition. on construit la classe contact et on la remplit avec toutes les variables de la classe/ tous les members attributes
Contact::Contact(const std::string first_name, const std::string last_name,
				 const std::string nickname, const std::string phone_number,
				 const std::string darkest_secret) :
				_first_name(first_name),
				_last_name(last_name),
				_nickname(nickname),
				_phone_number(phone_number),
				_darkest_secret(darkest_secret) {
}

// fonction qui appartient a aucune classe
void get_input(const std::string& prompt, std::string& field) {
	std::cout << prompt << std::endl;
	std::getline(std::cin, field);
	if (std::cin.eof())
		exit(0);
	std::cout << field << std::endl;
}

//fonction membre de la classe contact 
void Contact::get_new_contact(void) {
	get_input("First Name:", this->_first_name);
	get_input("Last Name:", this->_last_name);
	get_input("Nickname:", this->_nickname);
	get_input("Phone Number:", this->_phone_number);
	get_input("Darkest Secret:", this->_darkest_secret);
}

// ?? empty mot reserve ?? 
bool Contact::check_if_valid(void)
{
	return !(this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty()
			 || this->_phone_number.empty() || this->_darkest_secret.empty());
}

//fonction membre de la classe contact
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