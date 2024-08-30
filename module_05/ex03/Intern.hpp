
#pragma once
#include <string>

class AForm;

class Intern
{
private:

	typedef AForm *(Intern::*_form)(const std::string &target);
	//ce typedef remplace lappel de Intern::get... sous simplement AFORM

	AForm *_getShrubbery(const std::string &target);
	AForm *_getRobotomy(const std::string &target);
	AForm *_getPresidential(const std::string &target);

public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string &formName,const std::string &formTarget);
};


