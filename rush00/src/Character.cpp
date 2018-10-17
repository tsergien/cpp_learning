#include "../includes/Character.hpp"

Character::Character(){}

Character::Character(int col, int row) : _col(col), _row(row), _x(1), _y((row / 2)), _health(100), _killed_en(0) {
	pos_bull = new bull[col];
	for (int i = 0; i < col; i++)
		pos_bull[i].x = -1;
}


Character::Character(Character const & other){*this = other;}

Character const & Character::operator=(Character const & other){
	_health = other.getHealth();
	_x = other._x;
	_y = other._y;
	_col = other._col;
	_row = other._row;
	_killed_en = other._killed_en;
	return *this;
}

Character::~Character(){}

void Character::recoverAP(){
	_health += 10;
	if (_health > 40)
		_health = 40;
}

int Character::getHealth() const{return _health;}

bool	Character::check_collision(int x, int y, Enemy *enemy) {
	if ((x == enemy->getX() && y == enemy->getY()) || (x == enemy->getX() && y == enemy->getY() + 1))
		return true;
	return false;
}

bool	Character::collision(Squad & enemies){
	for (int i = 0; i < enemies.getCount(); i++)
	{
		Enemy *enemy = enemies.getUnit(i);
		if (_x + 1 >= enemy->getX())
			if (check_collision(_x + 1, _y, enemy) ||
			check_collision(_x, _y + 1, enemy) || check_collision(_x, _y - 1, enemy))
				return true;
	}
	return false;
}

void	Character::move(int direct) {
	if (direct == 1)
		_y++;
	else if (direct == 2)
		_y--;
	if (_y < 2)
		_y = 2;
	if (_y >= _row - 2)
		_y = _row - 2;
}

void	Character::shoot(){
	for (int i = 0; i < _col; i++) {
		if (pos_bull[i].x == -1) {
			pos_bull[i].x = _x + 2;
			pos_bull[i].y = _y;
			break;
		}
	}
}

void Character::setX(int val){_x = val;}
void Character::setY(int val){_y = val;}
int Character::getKilled() const{return _killed_en;}
int Character::getX() const{return _x;}
int Character::getY() const{return _y;}
bull	*Character::getPos_bull() const {return pos_bull;}

//move bullets and kills enemies in case of collision
void	Character::move_all_bullets(Squad & enemies)
{
	for (int i = 0; i < _col; i++)
	{
		if (pos_bull[i].x == -1)
			continue ;
		pos_bull[i].x += 1;
		if (pos_bull[i].x >= _col)
		{
			pos_bull[i].x = -1;
			continue;
		}
		for (int j = 0; j < enemies.getCount(); j++)
		{
			Enemy *e = enemies.getUnit(j);
			if (e == NULL)
				break;
			if (e->is_killed_by(pos_bull[i].x, pos_bull[i].y))
			{
				_killed_en++;
				enemies.delete_enemy(j);
				j--;
				pos_bull[i].x = -1;
			}
		}
	}
}