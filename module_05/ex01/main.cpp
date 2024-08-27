#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  std::cout << "------------- Main for ex01 : the Forms ---------- "
            << std::endl;

  try {
    Bureaucrat bureaucrat_1("Bureaucrat_1", 50);
    Bureaucrat bureaucrat_2("Bureaucrat_2", 100);
    Form form_1("Form_1", 0, 5);

    std::cout << bureaucrat_1 << std::endl
              << bureaucrat_2 << std::endl
              << std::endl;

    std::cout << std::endl;

    std::cout << form_1 << std::endl;

    bureaucrat_1.signForm(form_1);
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << "Exception : " << e.what() << std::endl;
  }

  catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << "Exception : " << e.what() << std::endl;
  }

  catch (std::exception &e) {
    std::cerr << "Exception : " << e.what() << std::endl;
  }

  return (0);
}