#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  {
    std::cout << "-------------  Form can be signed !  ---------- "
              << std::endl;

    try {
      Bureaucrat Emma("B1", 100);
      Form form_1("F1", 100, 100);

      std::cout << Emma << std::endl << std::endl;

      std::cout << std::endl;

      std::cout << form_1 << std::endl;

      Emma.signForm(form_1);

      std::cout << std::endl;

      std::cout << form_1 << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }

    catch (const Bureaucrat::GradeTooHighException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }

    catch (std::exception &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }
  }
  {
    std::cout << "-------------  too high exception ---------- " << std::endl;

    try {
      Bureaucrat Emma("B1", 2);
      Form form_1("F1", 5, 5);

      std::cout << Emma << std::endl << std::endl;

      std::cout << std::endl;

      std::cout << form_1 << std::endl;

      Emma.signForm(form_1);
    } catch (const Bureaucrat::GradeTooLowException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }

    catch (const Bureaucrat::GradeTooHighException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }

    catch (std::exception &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }
  }
  {
    std::cout << "-------------  too low exception ---------- " << std::endl;

    try {
      Bureaucrat Emma("B1", 50);
      Form form_1("F1", 151, 5);

      std::cout << Emma << std::endl << std::endl;

      std::cout << std::endl;

      std::cout << form_1 << std::endl;

      Emma.signForm(form_1);
    } catch (const Bureaucrat::GradeTooLowException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }

    catch (const Bureaucrat::GradeTooHighException &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }

    catch (std::exception &e) {
      std::cerr << "Exception : " << e.what() << std::endl;
    }
  }
  return (0);
}