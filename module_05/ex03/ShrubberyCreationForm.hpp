
#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm 
{
    public:

        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
        void action() const;
    
    private:

        std::string _target;
};
