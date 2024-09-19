#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
  std::cout << "\n\t\tBASIC TESTS\n" << std::endl;
  {
    try {
      Array<int> *intArrayPtr = new Array<int>(5);
      std::cout << (*intArrayPtr)[4] << std::endl;
      delete intArrayPtr;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }

    try {
      Array<int> intArray(MAX_VALUE);
      for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i;
      }
      std::cout << "\nArray<int> is: ";
      printArray(intArray);
      std::cout << std::endl;
      std::cout << " size: " << intArray.size() << std::endl;
    } catch (std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
      Array<std::string> stringArray(5);
      stringArray[0] = "hey";
      stringArray[1] = "you";
      stringArray[2] = "you";

      std::cout << "\nArray<std::string> is: ";
      printArray(stringArray);
      std::cout << std::endl;

      std::cout << " size: " << stringArray.size() << std::endl;

    } catch (std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
  }
  std::cout << "\n\t\t OUT OF RANGE TESTS\n" << std::endl;
  {
    try {
      Array<int> intArray(3);
      for (unsigned int i = 0; i < 5; ++i) {
        intArray[i] = i;
      }
      std::cout << "Array<int> is: ";
      printArray(intArray);
    } catch (std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
      Array<std::string> stringArray(2);
      stringArray[0] = "hey";
      stringArray[1] = "you";
      stringArray[2] = "you";

      std::cout << "Array<std::string> is: ";
      printArray(stringArray);
    } catch (std::exception &e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }
  }
  //   std::cout << "\n\t\tOTHER OUT OF RANGE TESTS\n" << std::endl;
  //   {
  //     try {
  //       Array<int> a(-2);
  //     } catch (std::exception &e) {
  //       std::cerr << "Exception: " << e.what() << std::endl;
  //     }
  //   }
  //   try {
  //     Array<int> a(MAX_VALUE);
  //     a[MAX_VALUE] = 0;
  //   } catch (std::exception &e) {
  //     std::cerr << "Exception: " << e.what() << std::endl;
  //   }
  //   std::cout << "\n\t\tDEEP COPY TESTS\n" << std::endl;
  //   try {
  //     {
  //       Array<float> f(5);
  //       Array<float> copy(f);

  //       std::cout << "array f is : ";
  //       printArray(f);

  //       std::cout << "array copy from f is : ";
  //       printArray(copy);

  //       for (unsigned int i = 0; i < copy.size(); i++) {
  //         copy[i] = 5;
  //       }
  //       std::cout << "all values of copy array are now 5. " << std::endl;

  //       std::cout << "array f is : ";
  //       printArray(f);

  //       std::cout << "array copy from f is : ";
  //       printArray(copy);
  //     }
  //   } catch (std::exception &e) {
  //     std::cerr << "Exception: " << e.what() << std::endl;
  //   }
  return 0;
}
