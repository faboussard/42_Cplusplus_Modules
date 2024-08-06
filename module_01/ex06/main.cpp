#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "No complain !";
		return 1;
	}
	std::string s1 = "INFO";
	std::string s2 = "DEBUG";
	std::string s3 = "ERROR";
	std::string s4 = "WARNING";
	std::string log = argv[1];
	if (s1.compare(log) != 0 || s2.compare(log) != 0 || s3.compare(log) != 0
	|| s4.compare(log) != 0 )
		std::cerr << "log level is either INFO DEBUG ERROR OR WARNING ";

	Harl harl;
	harl.complaintsFilter(log);
	return 0;
}
