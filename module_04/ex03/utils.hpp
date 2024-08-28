#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>

#define DEFAULT_CONSTRUCTOR_MESSAGE " Default Constructor called"
#define CONSTRUCTOR_MESSAGE " Type Constructor called"
#define COPY_CONSTRUCTOR_MESSAGE " Copy Constructor called"
#define COPY_ASSIGNMENT_MESSAGE " Copy Assignment operator called"
#define DESTRUCTOR_MESSAGE " Destructor called"

void construct_message(const std::string &name, const std::string &color, const std::string message);


#define RESET "\033[0m"
#define MAGENTA "\033[1;35m"
#define BGWHITE "\033[47m"

# define BOLD	"\e[1m"
# define DIM	"\e[2m"
# define ITAL	"\e[3m"
# define ULINE	"\e[4m"

# define BLACK	"\e[30m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"
# define WHITE	"\e[37m"

# define BRIGHT_BLACK	"\e[90m"
# define BRIGHT_RED		"\e[91m"
# define BRIGHT_GREEN	"\e[92m"
# define BRIGHT_YELLOW	"\e[93m"
# define BRIGHT_BLUE	"\e[94m"
# define BRIGHT_PURPLE	"\e[95m"
# define BRIGHT_CYAN	"\e[96m"
# define BRIGHT_WHITE	"\e[97m"

# define BG_BLACK	"\e[40m"
# define BG_RED		"\e[41m"
# define BG_GREEN	"\e[42m"
# define BG_YELLOW	"\e[43m"
# define BG_BLUE	"\e[44m"
# define BG_PURPLE	"\e[45m"
# define BG_CYAN	"\e[46m"
# define BG_WHITE	"\e[47m"

# define BG_BRIGHT_BLACK	"\e[100m"
# define BG_BRIGHT_RED		"\e[101m"
# define BG_BRIGHT_GREEN	"\e[102m"
# define BG_BRIGHT_YELLOW	"\e[103m"
# define BG_BRIGHT_BLUE		"\e[104m"
# define BG_BRIGHT_PURPLE	"\e[105m"
# define BG_BRIGHT_CYAN		"\e[106m"
# define BG_BRIGHT_WHITE	"\e[107m"

#endif
