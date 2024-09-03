
#include "RobotomyRequestForm.hpp"
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45) 
{
    _target = "none";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("RobotomyRequestForm", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):AForm("RobotomyRequestForm", 72, 45) 
{
    _target = src._target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
    _target = src._target;
    return *this;
}

void RobotomyRequestForm::action() const 
{
    srand((long) this);
	if (rand() % 2)
	{
        std::cout << "RIZZZZZZZZZZZZZZ..." << std::endl
                  << _target << " has been robotomized successfully." << std::endl;
    }
    else 
	{
        std::cout << _target << " robotomy failed." << std::endl;
    }
}
