#include "BitcoinExchange.hpp"

/*eror management
 * The program name is btc.
• Your program must take a file as argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000.*/


/*07:04:55 fanny@fanny-desktop ex00 ±|master ✗|→ ./btc input.txt
Error: Malformed line in input file: 2001-42-42
Warning: No exchange rate found for date: 2007-01-09
Warning: No exchange rate found for date: 2008-05-10

Warning: No exchange rate found for date: 2009--1-09   -- doit generer une erreur malforme line

Warning: No exchange rate found for date: 2009-01-32
Warning: No exchange rate found for date: 2009-01-33
Warning: No exchange rate found for date: 2009-03-06
Warning: No exchange rate found for date: 2009-31-09
Warning: No exchange rate found for date: 2011-01 09
Warning: No exchange rate found for date: 2011-01-*9
Warning: No exchange rate found for date: 2011-01-03
Warning: No exchange rate found for date: 2011-01-09
Warning: No exchange rate found for date: 2011-01-09
Warning: No exchange rate found for date: 2011-u2-03
Warning: No exchange rate found for date: 2012-01-11
Warning: No exchange rate found for date: 2016-02-29
Warning: No exchange rate found for date: 2020-01-01
Warning: No exchange rate found for date: 2025-01-01
Warning: No exchange rate found for date: 20581-01-11
*/



/*
 * If the date used in the input does not exist in your DB then you
must use the closest date contained in your DB. Be careful to use the
lower date and not the upper one.
 */
void check_args(int argc)
{
	if (argc != 2)
	{
		std::cerr << WRONG_ARGS_ERROR_MESSAGE << std::endl;
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	check_args(argc);

	std::string inputFile = std::string("Data/") + std::string(argv[1]);
	std::string dataFile(DATABASE);

	BitcoinExchange exchange(inputFile, dataFile);

	try
	{
		exchange.findRate();
//		exchange.print_database(exchange.getDatabaseMap());
		exchange.print_database(exchange.getInputbaseMap());


	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
