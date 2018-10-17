#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#define MSIZE 4

class Character : public ICharacter
{
	std::string name_;
	AMateria* materia[MSIZE];
public:
	Character();
	Character(std::string name);
	Character(Character const & other);
	Character const & operator=(Character const & other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, Character& target);
};

#endif