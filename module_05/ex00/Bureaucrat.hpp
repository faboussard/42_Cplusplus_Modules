#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	std::string const &_name;
	int _grade;


public:
	Bureaucrat();

	Bureaucrat(const std::string &name, int grade);

	~Bureaucrat();

	Bureaucrat(const Bureaucrat &copy);

	Bureaucrat &operator=(const Bureaucrat src);

	std::string const &getName() const;

	int getGrade() const;

	void incrementGrade();

	void incrementGrade(int i);

	void decrementGrade();

	void decrementGrade(int i);

	static int const highestGrade = 1;
	static int const lowestGrade = 150;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);

#endif
