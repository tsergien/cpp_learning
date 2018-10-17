#ifndef ICE_HPP
#define ICE_HPP
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria
{
private:
	
public:
	Ice();
	Ice(Ice const & other);
	Ice const & operator=(Ice const & other);
	~Ice();

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};

#endif