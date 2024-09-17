#include "BitcoinExchange.hpp"

/*eror management
 * The program name is btc.
• Your program must take a file as argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and
1000.*/

void check_args(int argc) {
  if (argc != 2) {
    std::cerr << WRONG_ARGS_ERROR_MESSAGE << std::endl;
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char **argv) {
  check_args(argc);

  std::string inputFile = std::string("Data/") + std::string(argv[1]);
  std::string dataFile(DATABASE);

  BitcoinExchange exchange(inputFile, dataFile);


  try {
    exchange.findRate();
	  std::cout << exchange;

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
