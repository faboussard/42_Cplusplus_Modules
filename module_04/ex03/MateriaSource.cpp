

#include "MateriaSource.hpp"
#include "utils.hpp"

/*============================================================================*/
/*       Constructors */
/*============================================================================*/


MateriaSource::MateriaSource() {
	initMaterias(MAX_ITEMS_NUMBERS, _materias);
	construct_message("MateriaSource", CYAN, DEFAULT_CONSTRUCTOR_MESSAGE);
}

MateriaSource::~MateriaSource() {
	deleteMaterias(MAX_ITEMS_NUMBERS, _materias);
	construct_message("MateriaSource", CYAN, DESTRUCTOR_MESSAGE);
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	initMaterias(MAX_ITEMS_NUMBERS, _materias);  // Init the array before copying
	copyMaterias(MAX_ITEMS_NUMBERS, _materias, src._materias);
	construct_message("MateriaSource", CYAN, COPY_CONSTRUCTOR_MESSAGE);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
	if (this != &src) {
		deleteMaterias(MAX_ITEMS_NUMBERS, _materias);  // Clear the current materias
		copyMaterias(MAX_ITEMS_NUMBERS, _materias, src._materias);  // Copy the new ones
		construct_message("MateriaSource", CYAN, COPY_ASSIGNMENT_MESSAGE);
	}
	return *this;
}

/*============================================================================*/
/*       member functions */
/*============================================================================*/

void MateriaSource::learnMateria(AMateria *materia) {
  for (int i = 0; i < 4; i++) {
    if (_materias[i] == NULL) {
      _materias[i] = materia;
      return;
    }
  }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < 4; i++) {
    if (_materias[i] != NULL && _materias[i]->getType() == type)
      return (_materias[i]->clone());
  }
  return (NULL);
}
