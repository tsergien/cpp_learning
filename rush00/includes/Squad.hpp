#ifndef SQUAD_HPP
#define SQUAD_HPP
#include <iostream>
#include "Enemy.hpp"

typedef struct s_list
{
	Enemy		*enemy;
	s_list		*next;
}				t_list;

class Squad
{
	int		_n;
	t_list	*enemies;
public:
	Squad();
	~Squad();
	Squad(Squad const & other);
	Squad const & operator=(Squad const & other);

	int getCount() const;
	Enemy* getUnit(int) const;
	int push(Enemy* enemy);
	void	delete_enemy(int ind);
	void	delete_all();

	void	move_all_enemies();
	void	init_push(int cols, int rows);//create initial 5 random ships
};

#endif