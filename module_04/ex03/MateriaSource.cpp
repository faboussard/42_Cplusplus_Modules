

#include "MateriaSource.hpp"
#include "utils.hpp"

/*============================================================================*/
/*       Constructors */
/*============================================================================*/


MateriaSource::MateriaSource()
{
	initMaterias(_materias);
	construct_message("MateriaSource", BRIGHT_PURPLE, DEFAULT_CONSTRUCTOR_MESSAGE);
}

MateriaSource::~MateriaSource()
{
	deleteMaterias(_materias);
	construct_message("MateriaSource", BRIGHT_PURPLE, DESTRUCTOR_MESSAGE);
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	if (this != &src)
	{
		copyMaterias(_materias, src._materias);
	}
	construct_message("MateriaSource", BRIGHT_PURPLE, COPY_CONSTRUCTOR_MESSAGE);
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & src)
{
	if (this != &src)
	{
		deleteMaterias(_materias);
		copyMaterias(_materias, src._materias);
		construct_message("MateriaSource", BRIGHT_PURPLE, COPY_ASSIGNMENT_MESSAGE);
	}
	return *this;
}


/*============================================================================*/
/*       member functions */
/*============================================================================*/

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = materia;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] != NULL && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	return (NULL);
}
