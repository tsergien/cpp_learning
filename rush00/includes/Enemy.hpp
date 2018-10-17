#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>

class Enemy
{
protected:
	int _x;
	int _y;
	int _hp;

public:
	Enemy();
	Enemy(int x, int y, int hp);
	Enemy(Enemy const & other);
	Enemy const & operator=(Enemy const & other);
	virtual ~Enemy();

	virtual char getType() const;
	int getHP() const;
	int getX() const;
	int getY() const;

	void setX(int val);
	void setY(int val);
	virtual void takeDamage(int);
	static Enemy * random(int col, int row);
	virtual bool 	is_killed_by(int x, int y);
};

#endif

