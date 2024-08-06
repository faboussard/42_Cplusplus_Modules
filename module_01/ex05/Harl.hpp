#ifndef CPP_HARL_HPP
#define CPP_HARL_HPP

#include <string>
#include <iostream>

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	void complain( std::string level);
};

#endif //CPP_HARL_HPP
