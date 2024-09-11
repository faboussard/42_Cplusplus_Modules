#pragma once

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>
# include <cerrno>
# include <ctime>


# 	define DATABASE "../Data/data.csv"

# 	define INPUTFILE "../Data/input.txt"

#define BAD_OPENING_ERROR_MESSAGE "Error: Please enter an input file as argument"
#define WRONG_ARGS_ERROR_MESSAGE "Error: FILE COULD NOT OPEN"

class BitcoinExchange
{
	typedef std::map<std::string, float> map;

private:
	map _database;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();
};