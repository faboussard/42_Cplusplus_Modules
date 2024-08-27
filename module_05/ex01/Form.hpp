#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool _isSigned;
  const int _signGrade;
  const int _execGrade;

public:
  Form(std::string const &_name, const int signGrade, const int execGrade);
  Form(const Form &src);
  ~Form();
  Form &operator=(const Form &src);

  const std::string &getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void beSigned(Bureaucrat const &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &stream, Form &form);

#endif
