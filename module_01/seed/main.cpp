#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void check_args(int argc) {
  if (argc != 4) {
    std::cerr << "Error: Please enter exactly three arguments: a filename and "
                 "two strings."
              << std::endl;
    exit(EXIT_FAILURE);
  }
}

void open_files(const char *inputFilename, std::ifstream &infile,
                const char *outputFileName, std::ofstream &outfile) {
  infile.open(inputFilename);
  if (!infile.is_open()) {
    std::cerr << "Error: Unable to open input file: " << inputFilename
              << std::endl;
    exit(EXIT_FAILURE);
  }
  outfile.open(outputFileName);
  if (!outfile.is_open()) {
    std::cerr << "Error: Unable to open output file: " << outputFileName
              << std::endl;
    infile.close();
    exit(EXIT_FAILURE);
  }
}

std::string ft_replace(const std::string &line, const std::string &searchString,
                       const std::string &replaceString) {
  std::string modifiedLine = line;
  size_t startPos = 0;
  size_t searchLength = searchString.length();
  size_t replaceLength = replaceString.length();

  while ((startPos = modifiedLine.find(searchString, startPos)) !=
         std::string::npos) {
    modifiedLine.erase(startPos, searchLength);
    modifiedLine.insert(startPos, replaceString);
    startPos += replaceLength;
  }
  return modifiedLine;
}

void process_files(std::ifstream &infile, std::ofstream &outfile,
                   const std::string &searchString,
                   const std::string &replaceString) {
  std::string line;
  while (std::getline(infile, line)) {
    std::string modifiedLine = ft_replace(line, searchString, replaceString);
    outfile << modifiedLine << std::endl;
  }
}

int main(int argc, char **argv) {
  check_args(argc);

  std::string fileName(argv[1]);
  std::string searchString(argv[2]);
  std::string replaceString(argv[3]);

  std::string outputFileName = fileName + ".replace";

  std::ifstream infile;
  std::ofstream outfile;
  open_files(fileName.c_str(), infile, outputFileName.c_str(), outfile);
  process_files(infile, outfile, searchString, replaceString);

  infile.close();
  outfile.close();

  std::cout << "Content copied from " << fileName << " to " << outputFileName
            << std::endl;
  return EXIT_SUCCESS;
}
