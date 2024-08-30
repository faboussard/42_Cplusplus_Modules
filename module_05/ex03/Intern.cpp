#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void) other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	std::string formNames[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	_form formCreators[] = {&Intern::_getShrubbery, &Intern::_getRobotomy, &Intern::_getPresidential};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return (this->*formCreators[i])(formTarget);
		}
	}
	throw std::invalid_argument("Unknown form name: " + formName);
}


AForm *Intern::_getShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::_getRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::_getPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
