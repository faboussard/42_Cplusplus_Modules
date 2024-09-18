#include "ScalarConverter.hpp"

#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "Error: no parameters\n"
              << "Usage: <program> <literal>" << std::endl;
    return 1;
  }

  ScalarConverter::convert(argv[1]);

  return 0;
}
