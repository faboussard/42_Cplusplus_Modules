#include "Bureaucrat.hpp"

int main(void) {
  {
    try {
      Bureaucrat bureaucrat_1("B1", 1);
      Bureaucrat bureaucrat_2("B2", 100);

      std::cout << "------------- Main for : the Bureaucrats ---------- "
                << std::endl;
      std::cout << "------------- the good Bureaucrats ---------- "
                << std::endl;

      std::cout << bureaucrat_1 << std::endl
                << bureaucrat_2 << std::endl
                << std::endl;
      bureaucrat_1 = bureaucrat_2;

      std::cout << bureaucrat_1 << std::endl
                << bureaucrat_2 << std::endl
                << std::endl;

      bureaucrat_1.incrementGrade();
      bureaucrat_2.decrementGrade();
      bureaucrat_1.incrementGrade();
      bureaucrat_2.decrementGrade();

      std::cout << bureaucrat_1 << std::endl
                << bureaucrat_2 << std::endl
                << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }

    catch (const Bureaucrat::GradeTooHighException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }
  }
  {
    try {

      std::cout << "-------------  too high exception ---------- " << std::endl;

      Bureaucrat bureaucrat_3("Bureaucrat_1", 150);
      Bureaucrat bureaucrat_4("Bureaucrat_2", 1);
      std::cout << bureaucrat_3 << std::endl
                << bureaucrat_4 << std::endl
                << std::endl;

      bureaucrat_4.incrementGrade();
      bureaucrat_3.decrementGrade();

      std::cout << bureaucrat_3 << std::endl
                << bureaucrat_4 << std::endl
                << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }

    catch (const Bureaucrat::GradeTooHighException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }
  }
  {
    try {

      std::cout << "-------------  too low exception ---------- " << std::endl;

      Bureaucrat bureaucrat("Emma", 150);
      std::cout << bureaucrat << std::endl << std::endl;

      bureaucrat.decrementGrade();

      std::cout << bureaucrat << std::endl
                << bureaucrat << std::endl
                << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }

    catch (const Bureaucrat::GradeTooHighException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }
  }

  return (0);
}