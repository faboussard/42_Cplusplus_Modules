#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#define DATABASE "Data/data.csv"
#define WRONG_ARGS_ERROR_MESSAGE "Error: Please enter an input file as argument"
#define BAD_OPENING_ERROR_MESSAGE "Error: FILE COULD NOT OPEN"

#define COMA_SEPARATOR ','
#define DASH_SEPARATOR '|'


class BitcoinExchange
{
	typedef std::map<std::string, float> map;

private:
	void open_file(const char *filename, std::ifstream &infile);

	bool parse_line_datafile(const std::string &line, std::string &key, float &value);
	bool parse_line_inputfile(const std::string &line, std::string &key, float &value);

	void process_input_file(std::ifstream &infile);
	void process_data_file(std::ifstream &infile);


	std::string _inputFile;
	std::string _dataFile;
	map _databaseMap;
	map _inputDataMap;

public:
	BitcoinExchange(const std::string &inputFile, const std::string &dataFile);
	BitcoinExchange(const BitcoinExchange &rhs);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	map &getDatabaseMap();
	map &getInputbaseMap();
	std::string &getInputFile();
	std::string &getDataFile();

	bool extract_dataFile(std::string &fileName);
	bool extract_inputFile(std::string &fileName);
	void print_database(const map &database) const;


//	bool format_data();
	void process();
};

std::ostream &operator<<(std::ostream &stream, BitcoinExchange &bitcoinExchange);