#include "Base.hpp"
# include <cstdlib>


Base::~Base(){}

Base*	generate(void)
{
	srand(time(0));
	int	random = rand() % 3;

	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else if (random == 2)
		return (new C());
	return NULL;
}

void	identify(Base* p)
{
	if (p == NULL)
		std::cout << "NULL pointer" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C pointer" << std::endl;
	else
		std::cout << "Unknow pointer" << std::endl;
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A pointer" << std::endl;
		return;
	}
	catch (const std::exception& e) {}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B pointer" << std::endl;
		return;
	}
	catch (const std::exception& e) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C pointer" << std::endl;
		return;
	}
	catch (const std::exception& e) {}

	std::cout << "unknown pointer" << std::endl;
}