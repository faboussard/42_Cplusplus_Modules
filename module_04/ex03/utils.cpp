
#include <iostream>
#include <string>
#include "utils.hpp"

void construct_message(const std::string &name, const std::string &color, const std::string message)
{
	std::cout << color << name << message << RESET << std::endl;
}
