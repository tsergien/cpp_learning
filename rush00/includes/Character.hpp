#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "Squad.hpp"

struct bull {
	int x;
	int y;
};
class Character
{
private:

	int	_col;
	int	_row;
	int _x;
	int _y;
	int		_health;
	int		_killed_en;
	bull	*pos_bull;
	
public:
	Character();
	Character(int col, int row);
	Character(Character const & other);
	Character const & operator=(Character const & other);
	~Character();

	bool	check_collision(int x, int y, Enemy *enemy);
	void attack(Enemy* e);
	int getHealth() const;
	void recoverAP();

	bool	collision(Squad & enemies);
	void	move(int direct);
	void	shoot(void);

	void setX(int val);
	void setY(int val);
	int getX() const;
	int getY() const;
	int getKilled() const;
	bull	*getPos_bull() const;

	void	move_all_bullets(Squad & enemies);
};

#endif
