
#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm
{
    public:

        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
        void action() const;
    
	private:

        std::string _target;
};
