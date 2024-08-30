#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	Bureaucrat				belica = Bureaucrat("Belica", 1);
	Bureaucrat				lea = Bureaucrat("Lea", 149);
	Intern					joo = Intern();
	AForm*					form;

	form = joo.makeForm("shrubbery creation", "Groot");
	belica.signForm(*form);
	lea.executeForm(*form);
	belica.executeForm(*form);
	delete form;

	form = joo.makeForm("robotomy request", "Groot");
	belica.signForm(*form);
	lea.executeForm(*form);
	belica.executeForm(*form);
	delete form;

	form = joo.makeForm("presidential pardon", "Groot");
	belica.signForm(*form);
	lea.executeForm(*form);
	belica.executeForm(*form);
	delete form;

	return (0);
}
