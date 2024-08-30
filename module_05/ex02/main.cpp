#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat B1("B1", 1);
		Bureaucrat B2("B2", 150);

		PresidentialPardonForm presidentialForm("President");
		RobotomyRequestForm robotomyForm("Robot");
		ShrubberyCreationForm shrubberyForm("Garden");

		std::cout << B1 << std::endl;
		std::cout << B2 << std::endl;
		std::cout << std::endl;


		B1.signForm(presidentialForm);
		B1.signForm(robotomyForm);
		B1.signForm(shrubberyForm);
		std::cout << std::endl;


		B1.executeForm(presidentialForm);
		B1.executeForm(robotomyForm);
		B1.executeForm(shrubberyForm);
		std::cout << std::endl;


		B2.signForm(presidentialForm);
		B2.signForm(robotomyForm);
		B2.signForm(shrubberyForm);
		std::cout << std::endl;


		B2.executeForm(presidentialForm);
		B2.executeForm(robotomyForm);
		B2.executeForm(shrubberyForm);
		std::cout << std::endl;


	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
