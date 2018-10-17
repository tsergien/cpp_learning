#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
private:
	std::string type_;
	unsigned int xp_;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const & other);
	AMateria const & operator=(AMateria const & other);
	virtual ~AMateria();

	std::string const & getType() const;
	unsigned int getXP() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	void	setXP(unsigned int xp);
};

#endif