#include "Base.hpp"

int main()
{
	Base *base;

	Base *baseA = new A();
	Base *baseB = new B();
	Base *baseC = new C();

	base = generate();
	identify(base);
	identify(*base);

	identify(baseA);
	identify(baseB);
	identify(*baseC);

	delete baseA;
	delete baseB;
	delete baseC;

	return 0;
}