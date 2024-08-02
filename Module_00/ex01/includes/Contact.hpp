#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <stdlib.h>

class Contact
{

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

public:
	Contact(void);
	Contact(std::string FirstName,
			std::string LastName,
			std::string Nickname,
			std::string PhoneNumber,
			std::string DarkestSecret);

	const std::string &getFirstName(void) const;
	const std::string &getLastName(void) const;
	const std::string &getNickname(void) const;
	const std::string &getPhoneNumber(void) const;
	const std::string &getDarkestSecret(void) const;
	void get_new_contact(void);
	bool check_if_valid(void);


};

#endif //CONTACT_HPP

