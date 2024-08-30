#include "../includes/Utils.hpp"

bool get_input(const std::string &prompt, std::string &field) {
  std::cout << prompt;
  std::getline(std::cin, field);
  if (std::cin.eof())
    return true;
  return false;
}
