#include "RPN.hpp"

RPN::RPN(): std::stack<int>(){
}

RPN::RPN(const RPN &rhs): std::stack<int>(rhs){}