#include "../includes/Contact.hpp"


// Default initialization
Contact::Contact() {}

// En C++, les constructeurs ont le même nom que la classe et sont utilisés pour initialiser des objets de cette classe
// Parameterized constructor definition. on construit la classe contact et on la remplit avec toutes les variables de la classe/ tous les members attributes
//_first_name(first_name) signifie que le membre de la classe _first_name est initialisé avec la valeur de first_name passée en paramètre.
Contact::Contact(const std::string a, const std::string b,
				 const std::string c, const std::string d,
				 const std::string e) :
				_first_name(a),
				_last_name(b),
				_nickname(c),
				_phone_number(d),
				_darkest_secret(e) {
}
//Le corps du constructeur est vide ici. Toute l'initialisation nécessaire a été effectuée dans la liste d'initialisation.

/*
int main ()
{
  std::string content;
  std::string line;
  std::cout << "Please introduce a text. Enter an empty line to finish:\n";
  do {
    getline(std::cin,line);
    content += line + '\n';
  } while (!line.empty());
  std::cout << "The text you introduced was:\n" << content;
  return 0;
}*/

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