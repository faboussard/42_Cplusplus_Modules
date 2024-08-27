#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    Bureaucrat bureaucrat_1("Bureaucrat_1", 1);
    Bureaucrat bureaucrat_2("Bureaucrat_2", 100);
    Form form_1("Form_1", 2, 5);

    std::cout << "------------- Main for ex01 : the Forms ---------- "
              << std::endl;

    std::cout << bureaucrat_1 << std::endl
              << bureaucrat_2 << std::endl
              << std::endl;

    bureaucrat_1.signForm(form_1);

  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << "Exception : " << e.what() << std::endl;
  }

  catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << "Exception : " << e.what() << std::endl;
  }

  return (0);
}