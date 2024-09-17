
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5)
{
    _target = "none";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):AForm("PresidentialPardonForm", 25, 5)
{
    _target = src._target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    _target = src._target;
    return *this;
}

void PresidentialPardonForm::action() const 
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
