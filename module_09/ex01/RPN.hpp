#pragma once

#include <iostream>
#include <stack>


enum Operation
{
	ADD = '+',
	SUBSTRACT = '-',
	MULTIPLY = '*',
	DIVIDE = '/',
};

class RPN
{
public:
	typedef std::stack<int> stackContainer;

	RPN();

	RPN(const RPN &rhs);

	RPN &operator=(const RPN &rhs);

	~RPN();

	void calculate(Operation operation);

	int add(int val1, int val2);

	int substract(int val1, int val2);

	int muliply(int val1, int val2);

	int divide(int val1, int val2);

};