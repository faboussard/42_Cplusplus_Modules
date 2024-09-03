#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	Bureaucrat				B1 = Bureaucrat("B1", 1);
	Bureaucrat				B2 = Bureaucrat("B2", 149);
	Intern					intern1 = Intern();
	AForm*					form;

	form = intern1.makeForm("ShrubberyCreationForm", "Target1");
	B1.signForm(*form);
	B2.executeForm(*form);
	B1.executeForm(*form);
	delete form;

	form = intern1.makeForm("RobotomyRequestForm", "Target2");
	B1.signForm(*form);
	B2.executeForm(*form);
	B1.executeForm(*form);
	delete form;

	form = intern1.makeForm("PresidentialPardonForm", "Target3");
	B1.signForm(*form);
	B2.executeForm(*form);
	B1.executeForm(*form);
	delete form;

	return (0);
}
