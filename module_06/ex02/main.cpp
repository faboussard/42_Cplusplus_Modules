#include "Base.hpp"

int main() {
  Base *base;

  Base *baseA = new A();
  Base *baseB = new B();
  Base *baseC = new C();

  std::cout << std::endl;

  std::cout << " identify random generation " << std::endl;

  std::cout << std::endl;

  base = generate();
  identify(base);
  identify(*base);

  delete base;

  std::cout << std::endl;

  std::cout << " identify function results " << std::endl;

  std::cout << std::endl;

  identify(baseA);
  identify(baseB);
  identify(*baseC);

  delete baseA;
  delete baseB;
  delete baseC;

  return 0;
}