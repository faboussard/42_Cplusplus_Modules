#include "Harl.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: harlFilter <level>" << std::endl;
    return EXIT_FAILURE;
  }

  Harl harl;
  std::string level = argv[1];
  harl.complain(level);

  return EXIT_SUCCESS;
}