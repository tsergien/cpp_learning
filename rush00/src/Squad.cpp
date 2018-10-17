#include "../includes/Squad.hpp"

Squad::Squad() : _n(0), enemies(NULL){}

void	Squad::delete_all()
{
	for (int i = 0; i < _n; i++)
	{
		t_list *tmp = enemies->next;
		delete enemies->enemy;
		enemies->enemy = NULL;
		delete enemies;
		enemies = tmp;
	}
	_n = 0;
}

Squad::~Squad(){
	delete_all();
}
Squad::Squad(Squad const & other)
{
	*this = other;
}

Squad const & Squad::operator=(Squad const & other)
{
	if (this == &other)
		return *this;
	delete_all();
	_n = other.getCount();
	for (int i = 0; i < other.getCount(); i++)
		push(other.getUnit(i));
	return *this;
}

int Squad::getCount() const {return _n;}

Enemy* Squad::getUnit(int ind) const 
{
	if (ind < 0 || ind >= _n)
		return NULL;
	t_list *tmp;
	tmp = enemies;
	for (int i = 0; i < ind; i++)
		tmp = tmp->next;
	if ( tmp)
		return tmp->enemy;
	return NULL;
}

int Squad::push(Enemy* new_mem)
{
	t_list *tmp = enemies;
	if (!tmp)
	{
		enemies = new t_list;
		enemies->enemy = new_mem;
		enemies->next = NULL;
		_n = 1;
		return _n;
	}
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new t_list;
	tmp->next->enemy = new_mem;
	tmp->next->next = NULL;
	return ++_n;
}


void	Squad::delete_enemy(int ind)
{
	if (ind < 0 || ind >= _n || _n == 0)
		return ;
	if (_n == 1) {
		delete enemies->enemy;
		enemies->enemy = NULL;
		delete enemies;
		enemies = NULL;
		_n--;
		return ;
	}
	t_list	*next;
	t_list	*tmp;
	tmp = enemies;
	if (ind == 0) {
		next = enemies->next;
		delete tmp->enemy;
		enemies->enemy = NULL;
		delete tmp;
		enemies = next;
		_n--;
		return ;
	}
	t_list	*prev;
	int		i = 0;

	while (tmp && tmp->next && i != ind - 1) {
		tmp = tmp->next;
	}
	prev = tmp;
	next = tmp->next->next;
	delete tmp->next->enemy;
	tmp->next->enemy = NULL;
	delete tmp->next;
	_n--;
}

void	Squad::init_push(int cols, int rows)
{
	push(Enemy::random(cols - (cols / 4), rows / 5));
	push(Enemy::random(cols - (cols / 4), rows / 3));
	push(Enemy::random(cols - (cols / 4), rows / 4));
	push(Enemy::random(cols - (cols / 5), rows / 3));
	push(Enemy::random(cols - (cols / 5), rows / 5));
}

void	Squad::move_all_enemies()
{
	t_list *tmp = enemies;
	t_list	*next;
	for (int i = 0; i < _n && tmp; i++)
	{
		tmp->enemy->setX(tmp->enemy->getX() - 1);
		next = tmp->next;
		if (tmp->enemy->getX() < 0)
			delete_enemy(i--);
		tmp = tmp->next;
	}
}
