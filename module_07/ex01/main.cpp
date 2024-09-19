#include "iter.hpp"
#include <iostream>

void upperChar(char &c) { c = toupper(c); }

int main() {

  std::cout << "\n";
  std::cout << "iter on int array" << std::endl;
  int intArray[] = {1, 2, 3, 4, 5};

  iter<int>(intArray, typeLenght(intArray), print);

  ///////////////////////////////////////////////////

  std::cout << "\n";
  std::cout << "iter on double array" << std::endl;
  double doubleArray[] = {1.1, 2.2, 3.3};

  iter<double>(doubleArray, typeLenght(doubleArray), print);

  ///////////////////////////////////////////////////

  std::cout << "\n";
  std::cout << "iter on char array" << std::endl;

  char charArray[] = {'H', 'e', 'l', 'l', 'o'};

  iter<char>(charArray, 5, print);
  std::cout << "to upper on char array"
            << std::endl; // to show iter works with another function
  iter<char>(charArray, typeLenght(charArray), upperChar);
  print(charArray);

  ///////////////////////////////////////////////////
  std::cout << "\n";
  std::cout << "iter on string array" << std::endl;

  std::string stringArray[] = {"Hello", "World", "from", "C++"};
  iter<std::string>(stringArray, typeLenght(stringArray), print);

  ///////////////////////////////////////////////////
  std::cout << "\n";
  std::cout << "iter on const string array" << std::endl;

  const std::string conststringArray[] = {"Hello", "World", "from", "C++"};
  iter<std::string>(conststringArray, typeLenght(conststringArray), print);

  return 0;
}