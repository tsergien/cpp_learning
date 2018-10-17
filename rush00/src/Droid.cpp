#include "../includes/Droid.hpp"

Droid::Droid(){}

Droid::Droid(int x, int y, int hp) : Enemy(x, y, hp){}

Droid::Droid(Droid const & other){
	*this = other;
}
Droid const & Droid::operator=(Droid const & other){
		_hp = other.getHP();
	_x = other.getX();
	_y = other.getY();
	return *this;
}
Droid::~Droid(){}

void Droid::takeDamage(int amount){
	Enemy::takeDamage(amount);
}

char	Droid::getType() const
{
	return 'o';
}

bool 	Droid::is_killed_by(int x, int y)
{
	if ((x == getX() && y == getY()) || (x == getX() && y == getY() + 1))
		return 1;
	if ((x == getX()+1 && y == getY()) || (x == getX()+1 && y == getY() + 1))
		return 1;
	return 0;
}