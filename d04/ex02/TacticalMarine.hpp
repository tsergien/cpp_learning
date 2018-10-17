#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP
#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	~TacticalMarine();
	TacticalMarine(TacticalMarine const & other);
	TacticalMarine const & operator=(TacticalMarine const & other);
	
	TacticalMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif