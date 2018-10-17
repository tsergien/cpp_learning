#ifndef SQUAD_HPP
#define SQUAD_HPP
#include <iostream>
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad
{
	int				_n;
	ISpaceMarine	**_unit;
public:
	Squad();
	~Squad();
	Squad(Squad const & other);
	Squad const & operator=(Squad const & other);

	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);
};

#endif