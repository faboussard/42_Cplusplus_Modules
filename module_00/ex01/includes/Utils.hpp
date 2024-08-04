#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <stdlib.h>
#include <string>

#define RESET "\033[0m"
#define WHITE "\033[1;37m"
#define BLACK "\033[1;30m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define BGWHITE "\033[47m"

bool get_input(const std::string &prompt, std::string &field);

#endif // UTILS_HPP
