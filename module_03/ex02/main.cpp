#include "Fixed.hpp"
#include <iostream>

int main() {
  Fixed a;
  Fixed b;

  // Initialisation des objets avec des valeurs différentes
  a = 5;
  b = 7;

  // Affichage des valeurs initiales
  std::cout << "a = " << a << ", b = " << b << std::endl;

  // Addition
  Fixed sum = a + b;
  std::cout << "a + b = " << sum << std::endl;

  // Soustraction
  Fixed diff = a - b;
  std::cout << "a - b = " << diff << std::endl;

  // Multiplication
  Fixed prod = a * b;
  std::cout << "a * b = " << prod << std::endl;

  // Division
  Fixed quot = a / b;
  std::cout << "a / b = " << quot << std::endl;

  // Comparaisons
  bool isEqual = a == b;
  bool isNotEqual = a != b;
  bool isGreater = a > b;
  bool isLess = a < b;
  bool isGreaterOrEqual = a >= b;
  bool isLessOrEqual = a <= b;

  std::cout << "Is a equal to b? " << (isEqual ? "Yes" : "No") << std::endl;
  std::cout << "Is a not equal to b? " << (isNotEqual ? "Yes" : "No")
            << std::endl;
  std::cout << "Is a greater than b? " << (isGreater ? "Yes" : "No")
            << std::endl;
  std::cout << "Is a less than b? " << (isLess ? "Yes" : "No") << std::endl;
  std::cout << "Is a greater than or equal to b? "
            << (isGreaterOrEqual ? "Yes" : "No") << std::endl;
  std::cout << "Is a less than or equal to b? "
            << (isLessOrEqual ? "Yes" : "No") << std::endl;

  return 0;
}
