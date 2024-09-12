#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(const std::string &inputFile, const std::string &dataFile)
		: _inputFile(inputFile), _dataFile(dataFile) {}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) : _inputFile(rhs._inputFile), _dataFile(rhs._dataFile)
{
	*this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		_database = rhs._database;
	}
	return *this;
}

