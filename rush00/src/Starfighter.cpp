#include "../includes/Starfighter.hpp"

Starfighter::Starfighter(){}

Starfighter::Starfighter(int x, int y, int hp) : Enemy(x, y, hp) {}

Starfighter::Starfighter(Starfighter const & other){
	*this = other;
}
Starfighter const & Starfighter::operator=(Starfighter const & other){
	_hp = other.getHP();
	_x = other.getX();
	_y = other.getY();
	return *this;
}
Starfighter::~Starfighter(){}

void Starfighter::takeDamage(int amount){
	_hp -= amount;
}

bool 	Starfighter::is_killed_by(int x, int y)
{
	if ((x == getX() && y == getY()) || (x == getX() && y == getY() + 1))
		takeDamage(25);
	else if ((x == getX()+1 && y == getY()) || (x == getX()+1 && y == getY() + 1))
		takeDamage(25);
	
	if (_hp <= 0)
		return 1;
	return 0;
}

char	Starfighter::getType() const{return '<';}