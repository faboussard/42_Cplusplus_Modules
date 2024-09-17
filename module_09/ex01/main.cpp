#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "RPN.hpp"

void processRPN(const std::string& expression)
{
	RPN rpn;

	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			int op = rpn.getOperator(token);
			if (op == -1)
			{
				std::cerr << "Error: Invalid operator \"" << token << "\"" << std::endl;
				return;
			}

			try
			{
				rpn.calculate(op);
			}
			catch (const std::runtime_error& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
				return;
			}
		}
		else
		{
			std::istringstream tokenStream(token);
			int value;
			if (!(tokenStream >> value))
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			rpn.push(value);
		}
	}
	if (!rpn.empty())
	{
		std::cout << "Result: " << rpn.top() << std::endl;
	}
	else
	{
		std::cerr << "Error: The RPN expression is empty" << std::endl;
	}
}

int checkArgs(int argc)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN <expression in reverse polish notation>" << std::endl;
		exit(EXIT_FAILURE);
	}
	return true;
}

int main(int argc, char* argv[])
{
	checkArgs(argc);
	std::string expression = argv[1];
	try
	{
		processRPN(expression);
	}
	catch (const std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
