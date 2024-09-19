#include "iter.hpp"
#include <iostream>

void upperChar(char &c) { c = toupper(c); }

int main() {

  int intArray[] = {1, 2, 3, 4, 5};
  double doubleArray[] = {1.1, 2.2, 3.3};
  std::string stringArray[] = {"Hello", "World", "from", "C++"};
  char charArray[] = {'H', 'e', 'l', 'l', 'o'};

  std::cout << "\n";
  std::cout << "iter on int array" << std::endl;
  iter<int>(intArray, 3, print); // will print only the first three numbers

  std::cout << "\n";
  std::cout << "iter on double array" << std::endl;
  iter<double>(doubleArray, 5,
               print); // will print weird numbers for the last two numbers

  std::cout << "\n";
  std::cout << "iter on char array" << std::endl;
  iter<char>(charArray, 5, print);
  std::cout << "to upper on char array"
            << std::endl; // to show iter works with another function
  iter<char>(charArray, 5, upperChar);
  print(charArray);

  std::cout << "\n";
  std::cout << "iter on string array with good lenght" << std::endl;

  size_t arrayLenght = sizeof(stringArray) / sizeof(stringArray[0]);
  iter<std::string>(stringArray, arrayLenght, print);

  return 0;
}