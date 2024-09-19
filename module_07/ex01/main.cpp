#include "iter.hpp"
#include <iostream>

template <typename T> void print(const T *array, size_t length) {
  for (i = 0; i < length; ++i) {
    std::cout << array[i] << " " << std::endl;
  }
}

int main() {
  int intArray[5] = {1, 2, 3, 4, 5};
  double doubleArray[] = {1.1, 2.2, 3.3};
  std::string stringArray[] = {"Hello", "World", "from", "C++"};
  char charArray[] = {'H', 'e', 'l', 'l', 'o'};

  iter<int>(intArray, 5, print);

  return 0;
}