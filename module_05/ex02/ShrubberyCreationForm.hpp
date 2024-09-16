
#pragma once

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(ShrubberyCreationForm const &src);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
  void action() const;

private:
  ShrubberyCreationForm();
  std::string _target;
};
