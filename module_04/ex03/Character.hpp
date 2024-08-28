#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(std::string const &name);
	Character(Character const &src);
	~Character();

	Character & operator=(Character const & src);

	std::string const &getName() const;
	void setName(std::string const & newName);
	void equip(AMateria *m);
	void unequip(int index);
	void use(int index, ICharacter &target);

private:
	std::string _name;
	AMateria *_inventory[4];
	void _initInventory();
	void _copyInventory(const Character &src);
	void _deleteInventory();
};

#endif