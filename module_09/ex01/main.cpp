#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "RPN.hpp"
#include <cctype>
#include <cstring>

void processRPN(const std::string& expression)
{
	RPN rpn;

	std::istringstream iss(expression);
	std::string token;
	bool flag = false;
	int count = 0;

	while (iss >> token)
	{
		int op = rpn.getOperator(token);
		if (op != -1)
		{
			if (flag == false)
			{
				std::cerr << "Error: invalid expression" << std::endl;
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
			count++;
			if (count == 2)
			{
				flag = true;
				count = 0;
			}
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

void checkArgsCount(int argc)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN <expression in reverse polish notation>" << std::endl;
		exit(EXIT_FAILURE);
	}
}

bool isOperator(const std::string &token) {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void checkOpOrDigits(char **argv) {
	int i = 1;

	while (argv[i]) {
		std::string arg = argv[i];

		if (isOperator(arg)) {
			i++;
			continue;
		}

		for (size_t j = 0; j < arg.length(); ++j) {
			if (!isdigit(arg[j]) && !(arg[j] == '-' && j == 0)) {
				std::cerr << "Error: invalid expression (invalid token: " << arg << ")" << std::endl;
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

void checkOpCount(char **argv) {
	int countOp = 0;
	int countNonOp = 0;
	int i = 1;

	while (argv[i]) {
		std::string arg = argv[i];

		if (isOperator(arg)) {
			countOp++;
		} else {
			countNonOp++;
		}
		i++;
	}

	if (countOp == 0) {
		std::cerr << "Error: no operator found in expression" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (countOp >= countNonOp) {
		std::cerr << "Error: invalid expression (more operators than operands)" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void checkArgs(int argc, char **argv) {
	checkArgsCount(argc);
//	checkOpOrDigits(argv);
	checkOpCount(argv);
}

int main(int argc, char* argv[]) {
	checkArgs(argc, argv);
	std::string expression = argv[1];
	try {
		processRPN(expression);
	}
	catch (const std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}