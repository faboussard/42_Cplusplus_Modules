#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#define DATABASE "Data/data.csv"
#define WRONG_ARGS_ERROR_MESSAGE "Error: Please enter an input file as argument"
#define BAD_OPENING_ERROR_MESSAGE "Error: FILE COULD NOT OPEN"

typedef std::map<std::string, float> map;

class BitcoinExchange
{
private:
	void open_file(const char *filename, std::ifstream &infile);
	bool parse_line(const std::string &line, std::string &key, float &value);
	void process_input_file(std::ifstream &infile);
	void process_data_file(std::ifstream &infile);
	void print_database(const map &database) const;

	std::string _inputFile;
	std::string _dataFile;
	map _database;      // Data from dataFile
	map _inputData;     // Data from inputFile

public:
	BitcoinExchange(const std::string &inputFile, const std::string &dataFile);
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	map &getDatabaseMap();
	map &getInputbaseMap();

	bool extract_data();
	bool format_data();
	void process();
};

std::ostream &operator<<(std::ostream &stream, BitcoinExchange &bitcoinExchange);