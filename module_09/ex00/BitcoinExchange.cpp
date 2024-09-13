#include "BitcoinExchange.hpp"
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(const std::string &inputFile, const std::string &dataFile)
		: _inputFile(inputFile), _dataFile(dataFile) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
		: _inputFile(rhs._inputFile), _dataFile(rhs._dataFile), _databaseMap(rhs._databaseMap), _inputDataMap(rhs._inputDataMap) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		_inputFile = rhs._inputFile;
		_dataFile = rhs._dataFile;
		_databaseMap = rhs._databaseMap;
		_inputDataMap = rhs._inputDataMap;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/*============================================================================*/
/*       getter 			   	                                        */
/*============================================================================*/


BitcoinExchange::map &BitcoinExchange::getDatabaseMap()
{
	return _databaseMap;
}

BitcoinExchange::map &BitcoinExchange::getInputbaseMap()
{
	return _inputDataMap;
}

std::string &BitcoinExchange::getInputFile()
{
	return _inputFile;
}

std::string &BitcoinExchange::getDataFile()
{
	return _dataFile;
}



/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/



void BitcoinExchange::open_file(const char *filename, std::ifstream &infile)
{
	infile.open(filename);
	if (!infile.is_open())
	{
		std::cerr << BAD_OPENING_ERROR_MESSAGE << filename << std::endl;
		exit(EXIT_FAILURE);
	}
}

bool BitcoinExchange::parse_line_datafile(const std::string &line, std::string &key, float &value)
{
	std::istringstream iss(line);
	std::getline(iss, key, COMA_SEPARATOR);
	std::string valueStr;
	std::getline(iss, valueStr);

	try
	{
		value = std::stof(valueStr);
		if (key.empty() || valueStr.empty())
			return false;
	}
	catch (const std::invalid_argument &)
	{
		return false;
	}
	return true;
}

bool BitcoinExchange::parse_line_inputfile(const std::string &line, std::string &key, float &value)
{
	std::istringstream iss(line);
	std::getline(iss, key, DASH_SEPARATOR);
	std::string valueStr;
	std::getline(iss, valueStr);

	try
	{
		value = std::stof(valueStr);
		if (key.empty() || valueStr.empty())
			return false;
	}
	catch (const std::invalid_argument &)
	{
		return false;
	}
	return true;
}

void BitcoinExchange::process_input_file(std::ifstream &infile)
{
	std::string line;
	std::string key;
	float value;

	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		if (parse_line_inputfile(line, key, value))
		{
			_inputDataMap[key] = value;
		}
		else
		{
			std::cerr << "Error: Malformed line in input file: " << line << std::endl;
		}
	}
}

void BitcoinExchange::process_data_file(std::ifstream &infile)
{
	std::string line;
	std::string key;
	float value;

	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		if (parse_line_datafile(line, key, value))
		{
			_databaseMap[key] = value;
		}
		else
		{
			std::cerr << "Error: Malformed line in data file: " << line << std::endl;
		}
	}
}

bool BitcoinExchange::extract_dataFile(std::string &fileName)
{
	try
	{
		std::ifstream data_infile;
		open_file(fileName.c_str(), data_infile);
		process_data_file(data_infile);
		data_infile.close();

		return true;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return false;
	}
}

bool BitcoinExchange::extract_inputFile(std::string &fileName)
{
	try
	{
		std::ifstream input_infile;
		open_file(fileName.c_str(), input_infile);
		process_input_file(input_infile);
		input_infile.close();

		return true;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return false;
	}
}

//void BitcoinExchange::print_database(const map &database) const
//{
//	for (map::const_iterator it = database.begin(); it != database.end(); ++it)
//	{
//		std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
//	}
//}

void BitcoinExchange::print_database(const map &database) const
{
	for (map::const_iterator it = database.begin(); it != database.end(); ++it)
	{
		std::cout << "Date: " << it->first << std::endl;
	}
}

float BitcoinExchange::calculate_with_rate(map::iterator it, float price)
{
	map::iterator rate_it = _databaseMap.lower_bound(it->first);

	if (rate_it == _databaseMap.end() || rate_it->first != it->first)
	{
		if (rate_it != _databaseMap.begin())
		{
			--rate_it;
		}
		else
		{
			return 0.0f;
		}
	}
	return price * rate_it->second;
}


void BitcoinExchange::findRate()
{
	if (!extract_inputFile(_inputFile) || !extract_dataFile(_dataFile))
	{
		std::cerr << "Error: could not extract input or data file." << std::endl;
		return;
	}

	for (map::iterator it = _inputDataMap.begin(); it != _inputDataMap.end(); ++it)
	{
		float price = it->second;
		float rate = calculate_with_rate(it, price);

		if (rate != 0.0f)
		{
			std::cout << it->first << " => " << price << " = " << rate << std::endl;
		}
		else
		{
			std::cerr << "Warning: No exchange rate found for date: " << it->first << std::endl;
		}
	}
}


