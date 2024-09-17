#include "RPN.hpp"

RPN::RPN(): stackContainer(){
}

RPN::RPN(const RPN &rhs): stackContainer(rhs){}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		std::stack<int>::operator=(rhs);
	}
	return *this;
}

RPN::~RPN(){}

int RPN::getOperator(const std::string op)
{
	if (op == "+")
		return ADD;
	if (op == "-")
		return SUBSTRACT;
	if (op == "*")
		return MULTIPLY;
	if (op == "/")
		return DIVIDE;
	else
		return -1;
}

void RPN::calculate(int operation)
{
	int val2 = this->top();
	this->pop();
	int val1 = this->top();
	this->pop();

	int result;
	switch (operation)
	{
		case ADD:
			result = add(val1, val2);
			break;
		case SUBSTRACT:
			result = substract(val1, val2);
			break;

		case MULTIPLY:
			result = multiply(val1, val2);
			break;

		case DIVIDE:
			result = divide(val1, val2);
			break;

		default:
			throw std::runtime_error("Invalid operation");
	}
	this->push(result);
}

int RPN::add(int val1, int val2)
{
	return val1 + val2;
}

int RPN::substract(int val1, int val2)
{
	return val1 - val2;
}

int RPN::multiply(int val1, int val2)
{
	return val1 * val2;
}

int RPN::divide(int val1, int val2)
{
	if (val2 == 0)
	{
		throw std::logic_error("Division by zero");
	}
	return val1 / val2;
}