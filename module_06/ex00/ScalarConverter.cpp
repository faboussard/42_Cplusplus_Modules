#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cmath>

/*============================================================================*/
/*       Constructors                                                           */
/*============================================================================*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	if (this != &other) {
		*this = other;
	}
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other) {}
	return *this;
}

ScalarConverter::~ScalarConverter() {}

/*============================================================================*/
/*       member functions                                                      */
/*============================================================================*/

void ScalarConverter::convert(const std::string& literal) {
	const std::string specialValues[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	const size_t specialCount = sizeof(specialValues) / sizeof(specialValues[0]);
	bool isSpecial = false;

	std::string charRepresentation = "impossible";
	int intRepresentation;
	float floatRepresentation;
	double doubleRepresentation;

	// Check for special values
	for (size_t i = 0; i < specialCount; ++i) {
		if (literal == specialValues[i]) {
			isSpecial = true;
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << (literal.substr(0, literal.length() - 1)) << std::endl;
			return;
		}
	}

	// Check if it's a single printable character
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		charRepresentation = "'" + literal + "'";
		intRepresentation = static_cast<int>(literal[0]);
		floatRepresentation = static_cast<float>(literal[0]);
		doubleRepresentation = static_cast<double>(literal[0]);

		std::cout << "char: " << charRepresentation << std::endl;
		std::cout << "int: " << intRepresentation << std::endl;
		std::cout << "float: " << floatRepresentation << ".0f" << std::endl;
		std::cout << "double: " << doubleRepresentation << ".0" << std::endl;
		return;
	}

	// Determine if the literal is a float or double
	bool isFloat = (literal.length() > 0 && literal[literal.length() - 1] == 'f');
	if (isFloat) {
		floatRepresentation = std::atof(literal.c_str());
		doubleRepresentation = static_cast<double>(floatRepresentation);
	} else {
		doubleRepresentation = std::atof(literal.c_str());
		floatRepresentation = static_cast<float>(doubleRepresentation);
	}

	// Handle int representation
	intRepresentation = static_cast<int>(doubleRepresentation);

	// Handle char representation
	if (intRepresentation >= 32 && intRepresentation <= 126) {
		charRepresentation = "'" + std::string(1, static_cast<char>(intRepresentation)) + "'";
	} else {
		charRepresentation = "Non displayable";
	}

	// Print results
	std::cout << "char: " << charRepresentation << std::endl;
	std::cout << "int: " << intRepresentation << std::endl;

	if (floatRepresentation == static_cast<int>(floatRepresentation)) {
		std::cout << "float: " << floatRepresentation << ".0f" << std::endl;
		std::cout << "double: " << doubleRepresentation << ".0" << std::endl;
	} else {
		std::cout << "float: " << floatRepresentation << "f" << std::endl;
		std::cout << "double: " << doubleRepresentation << std::endl;
	}
}
