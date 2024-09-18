#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>

/*============================================================================*/
/*       Constructors */
/*============================================================================*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  if (this != &other) {
  }
  return *this;
}

ScalarConverter::~ScalarConverter() {}

/*============================================================================*/
/*       member functions */
/*============================================================================*/

bool specialValuesAreFloat(const std::string &input) {
  return (input == "-inff" || input == "+inff" || input == "nanf" ||
          input == "inff");
}

bool isFloatOrDouble(const std::string &input) {
  return input.find('.') != std::string::npos;
}

void ScalarConverter::convert(const std::string &input) {
  const std::string specialValues[] = {"inf",  "inff", "-inff", "+inff",
                                       "nanf", "-inf", "+inf",  "nan"};
  const size_t specialCount = sizeof(specialValues) / sizeof(specialValues[0]);

  std::string stringRepresentation;
  int intRepresentation;
  float floatRepresentation;
  double doubleRepresentation;

  /*              special value case              */

  for (size_t i = 0; i < specialCount; ++i) {
    if (input == specialValues[i]) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;

      if (specialValuesAreFloat(input))
        std::cout << "float: " << input << std::endl;
      else
        std::cout << "float: " << input + "f" << std::endl;

      if (specialValuesAreFloat(input))
        std::cout << "double: " << (input.substr(0, input.length() - 1))
                  << std::endl;
      else
        std::cout << "double: " << input << std::endl;
      return;
    }
  }

  /*           		char           */

  if (input.length() == 1 && std::isprint(input[0]) &&
      !std::isdigit(input[0])) {
    stringRepresentation = static_cast<std::string>("'" + input + "'");
    intRepresentation = static_cast<int>(input[0]);
    floatRepresentation = static_cast<float>(input[0]);
    doubleRepresentation = static_cast<double>(input[0]);

    std::cout << "char: " << stringRepresentation << std::endl;
    std::cout << "int: " << intRepresentation << std::endl;
    std::cout << "float: " << floatRepresentation << ".0f" << std::endl;
    std::cout << "double: " << doubleRepresentation << ".0" << std::endl;
    return;
  }

  /*              strings           */

  bool isFloat = (input.length() > 0 && input[input.length() - 1] == 'f');
  if (isFloat) {
    floatRepresentation = std::atof(input.c_str());
    doubleRepresentation = static_cast<double>(floatRepresentation);
  } else {
    doubleRepresentation = std::atof(input.c_str());
    floatRepresentation = static_cast<float>(doubleRepresentation);
  }

  intRepresentation = static_cast<int>(doubleRepresentation);

  if ((!isFloatOrDouble(input)) && intRepresentation >= 32 &&
      intRepresentation <= 126) {
    stringRepresentation = static_cast<std::string>("'" + input + "'");
  } else {
    stringRepresentation = "Non displayable";
  }

  std::cout << "char: " << stringRepresentation << std::endl;
  std::cout << "int: " << intRepresentation << std::endl;

  if (floatRepresentation == static_cast<int>(intRepresentation)) {
    std::cout << "float: " << floatRepresentation << ".0f" << std::endl;
    std::cout << "double: " << doubleRepresentation << ".0" << std::endl;
  } else {
    std::cout << "float: " << floatRepresentation << "f" << std::endl;
    std::cout << "double: " << doubleRepresentation << std::endl;
  }
}
