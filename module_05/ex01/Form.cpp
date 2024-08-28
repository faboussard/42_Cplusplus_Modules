#include "Form.hpp"
#include "utils.hpp"

/*============================================================================*/
/*       Constructors */
/*============================================================================*/

Form::Form(std::string const &name, const int signGrade, const int execGrade)
    : _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade) {
  if (signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE)
    throw GradeTooHighException();
  if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
    throw GradeTooLowException();
  std::cout << " Form: ";
  CONSTRUCTOR_MESSAGE;
}

// Form::Form(const std::string name, int signGrade, int execGrade) {
//   this->_name = name;
//   this->_isSigned = false;
//   if (signGrade < 1 || execGrade < 1)
//     throw GradeTooHighException();
//   else if (signGrade > 150 || execGrade > 150)
//     throw GradeTooLowException();
//   else if (signGrade > execGrade)
//     throw GradeTooHighException();
//   else {
//     this->_signGrade = signGrade;
//     this->_execGrade = execGrade;
//     std::cout << "Custom Form " << this->_name << " created" << std::endl;
//   }
// }

Form::~Form() {
  std::cout << " Form: ";
  DESTRUCTOR_MESSAGE;
}

Form::Form(const Form &src)
    : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade) {
  std::cout << " Form: ";
  COPY_CONSTRUCTOR_MESSAGE;
}

Form &Form::operator=(const Form &src) {
  if (this != &src) {
    _isSigned = src._isSigned;
  }
  COPY_ASSIGNMENT_MESSAGE;
  return *this;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

const std::string &Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _isSigned; }

int Form::getSignGrade() const { return _signGrade; }

int Form::getExecGrade() const { return _execGrade; }

/*============================================================================*/
/*       Exceptions */
/*============================================================================*/

const char *Form::GradeTooHighException::what() const throw() {
  return "TooHighException";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "TooLowException";
}

/*============================================================================*/
/*       member functions */
/*============================================================================*/

void Form::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > _signGrade)
    throw Form::GradeTooLowException();
  _isSigned = true;
}

/*============================================================================*/
/*  			     Class overload */
/*============================================================================*/

std::ostream &operator<<(std::ostream &stream, Form &form) {
  stream << "Form name : " << form.getName() << std::endl
         << "Form is signed : " << form.getIsSigned() << std::endl
         << "Grade to sign : " << form.getSignGrade() << std::endl
         << "Grade to execute : " << form.getExecGrade() << std::endl;
  return (stream);
}