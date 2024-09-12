#pragma once

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>
# include <cerrno>
# include <ctime>
#include <vector>


# 	define DATABASE "Data/data.csv"

#define WRONG_ARGS_ERROR_MESSAGE "Please enter an input file as argument"
#define BAD_OPENING_ERROR_MESSAGE "FILE COULD NOT OPEN"


class BitcoinExchange
{
	typedef std::map<std::string, float> map;

private:
	void open_files(const char *filename, std::ifstream &infile);
	void process_files(std::ifstream &infile, std::vector<std::string> &lines);
	void print_extracted_array_of_lines(const std::vector<std::string> &lines);

	std::string _inputFile;
	std::string _dataFile;
	map _database;
public:
	BitcoinExchange(const std::string &inputFile, const std::string &dataFile);
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	bool extract_data();
};