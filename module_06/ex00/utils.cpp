
#include "utils.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

void construct_message(const std::string &name, const std::string &color,
                       const std::string message) {
  std::cout << color << name << message << RESET << std::endl;
}

void copyMaterias(int itemsNumber, AMateria **dest, AMateria *const *src) {
  for (int i = 0; i < itemsNumber; i++) {
    if (src[i] != NULL)
      dest[i] = src[i]->clone();
    else
      dest[i] = NULL;
  }
}

void initMaterias(int itemsNumber, AMateria **materia) {
  for (int i = 0; i < itemsNumber; i++)
    materia[i] = NULL;
}

void deleteMaterias(int itemsNumber, AMateria **materia) {
  for (int i = 0; i < itemsNumber; i++) {
    if (materia[i] != NULL) {
      delete materia[i];
      materia[i] = NULL;
    }
  }
}