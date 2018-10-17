#include "../includes/Enemy.hpp"
#include "../includes/Droid.hpp"
#include "../includes/Starfighter.hpp"

Enemy::Enemy(){}

Enemy::Enemy(int x, int y, int hp) : _x(x), _y(y), _hp(hp){}

Enemy::~Enemy(){}

Enemy::Enemy(Enemy const & other){
	*this = other;
}

Enemy const & Enemy::operator=(Enemy const & other){
	_hp = other.getHP();
	_x = other.getX();
	_y = other.getY();
	return *this;
}

char Enemy::getType() const{return 'o';}
int Enemy::getHP() const{return _hp;}

void Enemy::takeDamage(int amount){
	if (amount > 0)
		_hp -= amount;
}

int Enemy::getX() const{return _x;}
int Enemy::getY() const{return _y;}
void Enemy::setX(int val){_x = val;}
void Enemy::setY(int val){_y = val;}

Enemy * Enemy::random(int col, int row) {
	Enemy *enemy;
	switch (rand() % 2) {
		case 0:
			enemy = new Starfighter(col, row, 100);
			break;
		case 1:
			enemy = new Droid(col, row, 100);
			break;
	}
	return enemy;
}

bool 	Enemy::is_killed_by(int x, int y)
{
	if ((x == _x && y == _y) || (x == _x && y == _y + 1))
		return 1;
	if ((x == _x+1 && y == _y) || (x == _x+1 && y == _y + 1))
		return 1;
	return 0;
}
