
#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(RobotomyRequestForm const &src);
  ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
  void action() const;

private:
  RobotomyRequestForm();
  std::string _target;
};
