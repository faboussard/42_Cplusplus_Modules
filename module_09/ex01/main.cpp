#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "RPN.hpp"
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>

void checkArgsCount(int argc);
bool isOperator(char token);
void checkOpOrDigits(std::string &argv);
std::string remove_all_spaces(const std::string &s);
void checkDuplicatedOP(std::string &argv);
void checkArgv(std::string &argv);

void processRPN(const std::string &expression)
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
			catch (const std::runtime_error &e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
				return;
			}
		} else
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
	} else
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

////////////////////////////////////////////UTILS//////////////////////////////////////////////////////////////

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

void checkOpOrDigits(std::string &argv)
{
	int i = 1;

	while (argv[i])
	{

		if (!isdigit(argv[i]) && i == 0)
		{
			std::cerr << "Error: invalid expression (invalid token: " << argv << ")" << std::endl;
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

std::string remove_all_spaces(const std::string &s)
{
	std::string result = s;
	result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
	return result;
}



void checkDuplicatedOP(std::string &argv)
{
	int i = 1;

	std::string trimmed;
	trimmed = remove_all_spaces(argv);
	while (trimmed[i] && trimmed[i + 1])
	{
		if (isOperator(trimmed[i]) && (isOperator(trimmed[i + 1]) || trimmed[i + 1 ] == '\0'))
		{
			std::cerr << "Error: invalid expression (operator is duplicated " << trimmed[i] << ")" << std::endl;
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void checkOpCount(std::string &argv)
{
	int countOp = 0;
	int countNonOp = 0;
	int i = 1;

	while (argv[i])
	{
		if (isOperator(argv[i]))
			countOp++;
		else
			countNonOp++;
		i++;
	}
	if (countOp == 0)
	{
		std::cerr << "Error: no operator found in expression" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (countOp >= countNonOp)
	{
		std::cerr << "Error: invalid expression (more operators than operands)" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void checkArgv(std::string &argv)
{
	checkDuplicatedOP(argv);
//	checkOpOrDigits(argv);
	checkOpCount(argv);
}
