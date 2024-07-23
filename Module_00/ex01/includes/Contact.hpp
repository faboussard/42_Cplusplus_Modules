#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

//bonne indendation ?
//pourquopi le & ?
class Contact
{
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
	const std::string &PhoneNumber(void) const;
	const std::string &getDarkestSecret(void) const;

private:
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_Nickname;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;
};

#endif //CONTACT_HPP