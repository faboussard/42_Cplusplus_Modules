#include "ScalarConverter.hpp"
#include <climits>


/*============================================================================*/
/*       Constructors 			   	                                        */
/*============================================================================*/

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	if (this != &other)
		*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/
