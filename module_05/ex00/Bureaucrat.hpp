#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define DEFAULT_CONSTRUCTOR_MESSAGE \
	std::cout << MAGENTA << "Default Constructor called" << RESET << std::endl;
#define CONSTRUCTOR_MESSAGE \
	std::cout << MAGENTA << "Parametric Constructor called" << RESET << std::endl;
#define COPY_CONSTRUCTOR_MESSAGE \
	std::cout << MAGENTA << "Copy Constructor called" << RESET << std::endl;
#define COPY_ASSIGNMENT_MESSAGE \
	std::cout << MAGENTA << "Copy Assignment operator called" << RESET << std::endl;
#define DESTRUCTOR_MESSAGE \
	std::cout << MAGENTA << "Destructor called" << RESET << std::endl;


#define RESET "\033[0m"
#define WHITE "\033[1;37m"
#define BLACK "\033[1;30m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define BGWHITE "\033[47m"

class Bureaucrat
{
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
