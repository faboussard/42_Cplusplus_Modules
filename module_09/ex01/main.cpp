#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "RPN.hpp"
#include <cctype>
#include <algorithm>

void checkArgsCount(int argc);
bool isOperator(char token);
void checkOPisValid(std::string &argv);
void checkArgv(std::string &argv);

void processRPN(const std::string &expression)
{
	RPN rpn;

	std::istringstream iss(expression);
	std::string token;
	int operandCount = 0;

	while (iss >> token)
	{
		int op = rpn.getOperator(token);
		if (op != -1)
		{
			try
			{
				rpn.calculate(op);
				operandCount = 0;
			}
			catch (const std::runtime_error &e)
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
			operandCount++;
			if (operandCount > 2)
			{
				std::cerr << "Error: Too many consecutive operands without an operator" << std::endl;
				return;
			}
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



int main(int argc, char *argv[])
{
	checkArgsCount(argc);
	std::string expression = argv[1];
	checkArgv(expression);
	try
	{
		processRPN(expression);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

//////////////////////////////////////////// PARSING //////////////////////////////////////////////////////////////

void checkArgsCount(int argc)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN <expression in reverse polish notation>" << std::endl;
		exit(EXIT_FAILURE);
	}
}

bool isOperator(char token)
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}

void checkOPisValid(std::string &argv)
{
	int i = 1;

	while (argv[i])
	{
		if ( i != 0 && isOperator(argv[i]) && !isblank(argv[i - 1]))
		{
			std::cerr << "Error: blankspace is missing between operators" << std::endl;
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void checkOpCount(std::string &argv)
{
	int countOp = 0;
	int countDigit = 0;
	int i = 0;

	while (argv[i])
	{
		if (isOperator(argv[i]))
			countOp++;
		else if (isdigit(argv[i]))
		{
			countDigit++;
		}
		i++;
	}
	if (countOp == 0)
	{
		std::cerr << "Error: no operator found in expression" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (countOp >= countDigit)
	{
		std::cerr << "Error: invalid expression (more or equal operators than operands)" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void checkonlyDigitsorOp(std::string &argv)
{
	int i = 1;

	while (argv[i])
	{
		if ( !isOperator(argv[i]) && !isblank(argv[i]) && !isdigit(argv[i]))
		{
			std::cerr << "Error" << std::endl;
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void checkArgv(std::string &argv)
{
	checkonlyDigitsorOp(argv);
	checkOPisValid(argv);
	checkOpCount(argv);
}
