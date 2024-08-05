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
	std::string outputFileName = inputFileName + ".replace";
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
	size_t index;
	while (std::getline(infile, line))
	{
		size_t startPos = 0;
		while ((index = line.find(argv[2], startPos)) != std::string::npos && std::string(argv[2]).compare(""))
		{
			line.erase(index, std::string(argv[2]).length());
			line.insert(index, argv[3]);
			startPos = index + std::string(argv[3]).length();
		}
		outfile << line << '\n';

	}
	infile.close();
	outfile.close();
	std::cout << "Content copied from " << inputFileName << " to " << outputFileName << std::endl;
	return 0;
}
