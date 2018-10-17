#ifndef STARFIGHTER_HPP
#define STARFIGHTER_HPP
#include <iostream>
#include "Enemy.hpp"

class Starfighter : public Enemy
{
private:

	Starfighter();
public:
	Starfighter(int x, int y, int hp);
	Starfighter(Starfighter const & other);
	Starfighter const & operator=(Starfighter const & other);
	virtual ~Starfighter();

	void takeDamage(int);
	bool 	is_killed_by(int x, int y);
	char	getType() const;
};

#endif

