#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Please enter exactly three arguments: a filename and 2 strings" << std::endl;
		return 1;
	}
	std::string inputFileName(argv[1]);
	if (inputFileName.length() > 1000)
	{
		std::cerr << "Filename is too long. It should be of 1000 characters max" << std::endl;
		return 1;
	}
	std::string outputFileName = inputFileName + "_replace";
	std::ifstream infile(inputFileName.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Unable to open input file: " << inputFileName << std::endl;
		return 1;
	}
	std::ofstream outfile(outputFileName.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Unable to open output file: " << outputFileName << std::endl;
		infile.close();
		return 1;
	}
	std::string line;
	while (std::getline(infile, line))
	{
		outfile << line << '\n';
	}
	infile.close();
	outfile.close();
	std::cout << "Content copied from " << inputFileName << " to " << outputFileName << std::endl;
	return 0;
}
