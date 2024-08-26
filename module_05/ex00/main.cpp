#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bureaucrat_1("Bureaucrat_1", 50);
	Bureaucrat bureaucrat_2("Bureaucrat_2", 1000);

	std::cout << "------------- Main for ex00 : the Bureaucrats ---------- " << std::endl;

	std::cout << bureaucrat_1 << std::endl << bureaucrat_2 << std::endl << std::endl;

	bureaucrat_1 = bureaucrat_2;
	std::cout << bureaucrat_1 << std::endl << bureaucrat_2 << std::endl << std::endl;

	return (0);
}