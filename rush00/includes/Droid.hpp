#ifndef DROID_HPP
#define DROID_HPP
#include <iostream>
#include "Enemy.hpp"

class Droid : public Enemy
{
private:

public:
	Droid();
	Droid(int x, int y, int hp);
	Droid(Droid const & other);
	Droid const & operator=(Droid const & other);
	virtual ~Droid();

	virtual void takeDamage(int);
	char	getType() const;
	virtual bool 	is_killed_by(int x, int y);
};

#endif

