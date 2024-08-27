#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <string>

class Form;

class Bureaucrat {
private:
  std::string const _name;
  int _grade;

public:
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &src);
  Bureaucrat &operator=(const Bureaucrat &src);

  const std::string &getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  void signForm(Form &form) const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what(void) const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what(void) const throw();
  };
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);

#endif
