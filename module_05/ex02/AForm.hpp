#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _isSigned;
  const int _signGrade;
  const int _execGrade;

public:
  AForm(std::string const &_name, const int signGrade, const int execGrade);
  AForm(const AForm &src);
  virtual ~AForm();

  AForm &operator=(const AForm &src);

  const std::string &getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void beSigned(Bureaucrat const &bureaucrat);
  void execute(Bureaucrat const & executor) const;
  virtual void action() const = 0;


  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &stream, AForm &AForm);

#endif
