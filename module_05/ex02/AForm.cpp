#include "AForm.hpp"

/*============================================================================*/
/*       Constructors */
/*============================================================================*/

AForm::AForm(std::string const &name, const int signGrade, const int execGrade)
    : _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade) {
  if (signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE)
    throw GradeTooHighException();
  if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
    throw GradeTooLowException();
  std::cout << " AForm: ";
  CONSTRUCTOR_MESSAGE;
}

AForm::~AForm() {
  std::cout << " AForm: ";
  DESTRUCTOR_MESSAGE;
}

AForm::AForm(const AForm &src)
    : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade) {
  std::cout << " AForm: ";
  COPY_CONSTRUCTOR_MESSAGE;
}

AForm &AForm::operator=(const AForm &src) {
  if (this != &src) {
    _isSigned = src._isSigned;
  }
  COPY_ASSIGNMENT_MESSAGE;
  return *this;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

const std::string &AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _isSigned; }

int AForm::getSignGrade() const { return _signGrade; }

int AForm::getExecGrade() const { return _execGrade; }

/*============================================================================*/
/*       Exceptions */
/*============================================================================*/

const char *AForm::GradeTooHighException::what() const throw() {
  return "TooHighException";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "TooLowException";
}

/*============================================================================*/
/*       member functions */
/*============================================================================*/

void AForm::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > _signGrade)
    throw AForm::GradeTooLowException();
  _isSigned = true;
}

/*============================================================================*/
/*  			     Class overload */
/*============================================================================*/

std::ostream &operator<<(std::ostream &stream, AForm &AForm) {
  stream << "AForm name : " << AForm.getName() << std::endl
         << "AForm is signed : " << AForm.getIsSigned() << std::endl
         << "Grade to sign : " << AForm.getSignGrade() << std::endl
         << "Grade to execute : " << AForm.getExecGrade() << std::endl;
  return (stream);
}