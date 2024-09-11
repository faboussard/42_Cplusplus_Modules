#pragma once

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>
# include <cerrno>
# include <ctime>

# 	define DATABASE "../files/data.csv"

class BitcoinExchange {
private:
	std::map<std::string, float> _database;
};