#include "Harl.hpp"

//The use of void (Harl::*functions[])(void) allows you to store and call member functions dynamically
void Harl::complain(std::string level)
{
	int levelIndex = this->getLevel(level);
	switch (levelIndex)
	{
		case 0:
			this->debug();
			break;
		case 1:
			this->info();
			break;
		case 2:
			this->warning();
			break;
		case 3:
			this->error();
			break;
		default:
			std::cout <<  "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

int Harl::getLevel(const std::string &level)
{
	if  (level == "DEBUG") return 0;
	if (level == "INFO") return 1;
	if (level == "WARNING") return 2;
	if (level == "ERROR") return 3;
	return -1;
}

void	Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl \
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "\
	<< std::endl << "I really do!" << std::endl << std::endl;
	this->info();
}

void	Harl::info( void )
{
	std::cout << "[INFO]" << std::endl \
	<< "I cannot believe adding extra bacon costs more money. "\
	<< std::endl << "You didn't put enough bacon in my burger! " << std::endl \
	<< "If you did, I wouldn't be asking for more!" << std::endl << std::endl;
	this->warning();
}

void	Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl \
	<< "I think I deserve to have some extra bacon for free. "\
	<< std::endl << "I've been coming for years whereas you started working here since last month." \
	<< std::endl << std::endl;
	this->error();
}

void	Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl \
	<< "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}
