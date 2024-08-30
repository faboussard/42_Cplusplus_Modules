#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern(){}

Intern::Intern(const Intern &other){
	*this = intern;
}

Intern &Intern::operator=(const Intern &other){
	if (this != &other)
	{

	}
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget)
{

}