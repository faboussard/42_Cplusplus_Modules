#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void open_files(const char *inputFilename, std::ifstream &infile)
{
	infile.open(inputFilename);
	if (!infile.is_open())
	{
		std::cerr << BAD_OPENING_ERROR_MESSAGE << inputFilename << std::endl;
		infile.close();
		exit(EXIT_FAILURE);
	}
}

void process_files(std::ifstream &infile, std::vector<std::string> &lines)
{
	std::string line;
	while (std::getline(infile, line))
	{
		lines.push_back(line);
	}
}

void print_extracted_array_of_lines(std::vector<std::string> &lines)
{
	for (std::vector<std::string>::const_iterator it = lines.begin(); it != lines.end(); ++it)
		std::cout << *it << std::endl;
}

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

	(void)argc;
//	check_args(argc);

	std::string inputFile(argv[1]);
	std::string dataFile(DATABASE);


	std::ifstream input_infile;
	std::ifstream data_infile;


	std::ofstream outfile;

	open_files(inputFile.c_str(), input_infile);
	open_files(dataFile.c_str(), data_infile);


	std::vector<std::string> extracted_lines_input_file;
	std::vector<std::string> extracted_lines_data_file;

	process_files(input_infile, extracted_lines_input_file);
	process_files(data_infile, extracted_lines_data_file);

	input_infile.close();
	data_infile.close();


	print_extracted_array_of_lines(extracted_lines_input_file);
	print_extracted_array_of_lines(extracted_lines_data_file);
}