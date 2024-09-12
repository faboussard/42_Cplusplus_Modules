#include "BitcoinExchange.hpp"
#include <sstream>

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

void BitcoinExchange::open_file(const char *filename, std::ifstream &infile)
{
	infile.open(filename);
	if (!infile.is_open())
	{
		std::cerr << BAD_OPENING_ERROR_MESSAGE << filename << std::endl;
		exit(EXIT_FAILURE);
	}
}


/*============================================================================*/
/*       getter 			   	                                        */
/*============================================================================*/

map &BitcoinExchange::getDatabaseMap()
{
	return _databaseMap;
}

map &BitcoinExchange::getInputbaseMap()
{
	return _inputDataMap;
}

std::string &BitcoinExchange::getDataFile()
{
	return _dataFile;
}

std::string &BitcoinExchange::getInputFile()
{
	return _inputFile;
}



/*============================================================================*/
/*       member functions				                                       */
/*============================================================================*/

bool BitcoinExchange::parse_line_datafile(const std::string &line, std::string &key, float &value)
{
	std::istringstream iss(line);

	if (std::getline(iss, key, COMA_SEPARATOR) && (iss >> value))
	{
		return true;
	}
	return false;
}

bool BitcoinExchange::parse_line_inputfile(const std::string &line, std::string &key, float &value)
{
	std::istringstream iss(line);

	if (std::getline(iss, key, DASH_SEPARATOR) && (iss >> value))
	{
		return true;
	}
	return false;
}

void BitcoinExchange::process_input_file(std::ifstream &infile)
{
	std::string line;
	std::string key;
	float value;

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
		std::ifstream input_infile;
		open_file(fileName.c_str(), input_infile);
		process_data_file(input_infile);
		input_infile.close();

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

void BitcoinExchange::print_database(const map &database) const
{
	for (map::const_iterator it = database.begin(); it != database.end(); ++it)
	{
		std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
	}
}

void BitcoinExchange::process()
{
	if (extract_dataFile(_dataFile) && extract_inputFile(_inputFile))
	{
		for (const auto &inputPair : _inputDataMap)
		{
			auto it = _databaseMap.find(inputPair.first);
			if (it != _databaseMap.end())
			{
				float result = inputPair.second * it->second;
				std::cout << "Date: " << inputPair.first
						  << ", Price: " << inputPair.second
						  << ", Rate: " << it->second
						  << ", Result: " << result << std::endl;
			}
			else
			{
				std::cerr << "Warning: No exchange rate found for date: " << inputPair.first << std::endl;
			}
		}
	}
}



//std::ostream &operator<<(std::ostream &stream, BitcoinExchange &bitcoinExchange)
//{
//	map &database = getDatabaseMap();
//	map &inputbase = getInputbaseMap();
//	for ()
//	stream << "Date: " <<
//}