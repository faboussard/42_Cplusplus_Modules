#pragma once

#include <iostream>
#include <stack>


enum Operation
{
	ADD = 1,
	SUBSTRACT = 2,
	MULTIPLY = 3,
	DIVIDE = 4,
};

typedef std::stack<int> stackContainer;


class RPN : public stackContainer
{

public:

	RPN();

	RPN(const RPN &rhs);

	RPN &operator=(const RPN &rhs);

	~RPN();

	void calculate(int operation);

	int getOperator(const std::string op);

private:

	int add(int val1, int val2);

	int substract(int val1, int val2);

	int multiply(int val1, int val2);

	int divide(int val1, int val2);

};

int checkArgs(int ac, char **argv);