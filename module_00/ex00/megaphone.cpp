#include <iostream>
#include <string>

int main(int ac, char **av) {
  std::string const myString = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  if (ac == 1)
    std::cout << myString;
  for (int i = 1; i < ac; i++) {
    for (int j = 0; av[i][j]; j++)
      std::cout << (char)std::toupper(av[i][j]);
  }
  std::cout << std::endl;
  return 0;
}