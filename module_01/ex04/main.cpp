#include <iostream>
#include <string>
#include <fstream>

/*
 * Forbidden functions : std::string::replace
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected.
 */
int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << " Please enter 3 arguments: a filename and two strings" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		if (std::string(argv[i]).length() > 1000)
		{
			std::cerr << " String is too long. arguments should be of 1000 characters max" << std::endl;
			return 1;
		}
	}
	std::ifstream myfile(argv[1]);

	std::string line;
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			std::cout << line << '\n';
		}
		myfile.close();
	}
	else std::cout << "Unable to open file" << std::endl;

	std::ofstream newfile;
//	newfile.ft_replace();
}