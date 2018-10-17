#ifndef CURE_HPP
#define CURE_HPP
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria
{
private:
	
public:
	Cure();
	Cure(Cure const & other);
	Cure const & operator=(Cure const & other);
	~Cure();

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif