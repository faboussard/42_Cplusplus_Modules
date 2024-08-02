#ifndef CONTACT_HPP
#define CONTACT_HPP

# define RESET		"\033[0m"
# define WHITE 		"\033[1;37m"
# define BLACK		"\033[1;30m"
# define YELLOW		"\033[1;33m"
# define GREEN		"\033[1;32m"
# define RED		"\033[1;31m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define BGWHITE	"\033[47m"


# include <string>
# include <iostream>
#include "Utils.hpp"

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
	Contact(const std::string a,
			const std::string b,
			const std::string c,
			const std::string d,
			const std::string e);

	const std::string &getFirstName(void) const;
	const std::string &getLastName(void) const;
	const std::string &getNickname(void) const;
	const std::string &getPhoneNumber(void) const;
	const std::string &getDarkestSecret(void) const;
	void get_new_contact(void);
	bool check_if_valid(void);
};

#endif //CONTACT_HPP

