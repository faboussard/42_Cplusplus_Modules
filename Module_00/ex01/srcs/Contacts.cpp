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