#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void BitcoinExchange::open_files(const char *filename, std::ifstream &infile)
{
	infile.open(filename);
	if (!infile.is_open())
	{
		std::cerr << BAD_OPENING_ERROR_MESSAGE << filename << std::endl;
		infile.close();
		exit(EXIT_FAILURE);
	}
}

void BitcoinExchange::process_files(std::ifstream &infile, std::vector<std::string> &lines)
{
	std::string line;
	while (std::getline(infile, line))
	{
		lines.push_back(line);
	}
}

void BitcoinExchange::print_extracted_array_of_lines(const std::vector<std::string> &lines)
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
	//ajouter error handling sur argv1

}

bool BitcoinExchange::extract_data()
{
		try
		{
			std::ifstream input_infile;
			std::ifstream data_infile;

			open_files(_inputFile.c_str(), input_infile);
			open_files(_dataFile.c_str(), data_infile);

			std::vector<std::string> extracted_lines_input_file;
			std::vector<std::string> extracted_lines_data_file;

			process_files(input_infile, extracted_lines_input_file);
			process_files(data_infile, extracted_lines_data_file);

			input_infile.close();
			data_infile.close();

			print_extracted_array_of_lines(extracted_lines_input_file);
			print_extracted_array_of_lines(extracted_lines_data_file);

			return EXIT_SUCCESS;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return EXIT_FAILURE;
		}
}

int main(int argc, char **argv)
{
	check_args(argc);  // Vérifie si le nombre d'arguments est correct

	std::string inputFile = std::string("Data/") + std::string(argv[1]);
	std::string dataFile(DATABASE);

	BitcoinExchange* exchange = new BitcoinExchange(inputFile, dataFile);
	int result = exchange->extract_data();
	delete exchange;

	return result;
}