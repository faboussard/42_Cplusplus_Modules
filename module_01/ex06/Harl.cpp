#include "Harl.hpp"

//The use of void (Harl::*functions[])(void) allows you to store and call member functions dynamically
void Harl::complain(std::string level)
{
	std::string logs[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4 ; i++)
	{
		if (level == logs[i])
			(this->*(functionsptr[i]))();
	}
}

void (Harl::*functionsptr[])(void) = {&debug(), &Harl::info, &Harl::warning, &Harl::error};


void Harl::complaintsFilter(std::string level)
{
	int levelIndex;

}

void	Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl \
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "\
	<< std::endl << "I really do!" << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[INFO]" << std::endl \
	<< "I cannot believe adding extra bacon costs more money. "\
	<< std::endl << "You didn't put enough bacon in my burger! " << std::endl \
	<< "If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl \
	<< "I think I deserve to have some extra bacon for free. "\
	<< std::endl << "I've been coming for years whereas you started working here since last month." \
	<< std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl \
	<< "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}
