#include "Bureaucrat.hpp"
#include "general.hpp"

/*============================================================================*/
/*       Constructors 			   	                                        */
/*============================================================================*/

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	CONSTRUCTOR_MESSAGE;
}

Bureaucrat::~Bureaucrat()
{
	DESTRUCTOR_MESSAGE;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	COPY_CONSTRUCTOR_MESSAGE;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	COPY_ASSIGNMENT_MESSAGE;
	if (this != &src)
	{
		_grade = src._grade;
	}
	return *this;
}

/*============================================================================*/
/*       Accesors                                                             */
/*============================================================================*/

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/

void Bureaucrat::incrementGrade()
{
	int grade;

	grade = _grade;
	if (grade - 1 >= highestGrade)
		_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	int grade;

	grade = getGrade();
	if (grade + 1 <= lowestGrade)
		_grade += 1;
}

/*============================================================================*/
/*  			     Class overload		                                       */
/*============================================================================*/

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat)
{
	stream << bureaucrat.getName() << " , Bureaucrat grade : " << bureaucrat.getGrade();
	return stream;
}