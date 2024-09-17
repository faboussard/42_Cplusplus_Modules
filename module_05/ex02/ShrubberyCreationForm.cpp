
#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "none";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm("ShrubberyCreationForm", 145,
																					   137)
{
	_target = src._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	_target = src._target;
	return *this;
}

void ShrubberyCreationForm::action() const
{
	try
	{
		std::ofstream outFile((_target + "_shrubbery").c_str());
		if (!outFile.is_open())
		{
			std::cerr << "Error: Unable to open or create file: " << _target + "_shrubbery" << std::endl;
			return;
		}

		outFile << "                              _                   " << std::endl;
		outFile << "                           ,--.\\`-. __           " << std::endl;
		outFile << "                        _,.`. \\:/,  -._        " << std::endl;
		outFile << "                    ,-* _,.-;-*-.+*._ )        " << std::endl;
		outFile << "                   ( ,.* ,- / `.  \\.  `.        " << std::endl;
		outFile << "                 ,{   ,;  ,\\../\\  \\:   \\        " << std::endl;
		outFile << "                 (   ,/   / \\.,' :   ))  /       " << std::endl;
		outFile << "                  \\  |/   / \\.,'  /  / ,'        " << std::endl;
		outFile << "                   \\_)\\ ,' \\.,'  (  / )/          " << std::endl;
		outFile << "                      `  \\._,'                    " << std::endl;
		outFile << "                         \\../                     " << std::endl;
		outFile << "                          \\../                    " << std::endl;
		outFile << "                ~        ~\\../           ~~       " << std::endl;
		outFile << "         ~~          ~~   \\../   ~~   ~      ~~   " << std::endl;
		outFile << "    ~~    ~   ~~  __...---\\../-...__ ~~~     ~~   " << std::endl;
		outFile << "      ~~~~  ~_,--'        \\../      `--.__ ~~    ~~ " << std::endl;
		outFile << " ~~~  __,--                            --.__   ~~~ " << std::endl;
		outFile << "~~  ,--'                                         `--. " << std::endl;
		outFile << "  '------......______             ______......------` ~~ " << std::endl;
		outFile << "~~~   ~    ~~      ~ `````--------  ~~   ~     ~~    " << std::endl;
		outFile << "       ~~~~    ~~  ~~~~       ~~~~~~  ~ ~~   ~~ ~~~  ~ " << std::endl;
		outFile << "   ~~   ~   ~~~     ~~~ ~         ~~       ~~        " << std::endl;
		outFile << "             ~        ~~       ~~~       ~           " << std::endl;

		outFile.close();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

