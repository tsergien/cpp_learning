#include "Squad.hpp"

Squad::Squad() : _n(0), _unit(NULL){}
Squad::~Squad(){
	for (int i = 0; i < _n; i++)
		delete _unit[i];
	if (_n)
		delete [] _unit;
}
Squad::Squad(Squad const & other)
{
	*this = other;
}

Squad const & Squad::operator=(Squad const & other)
{
	if (this == &other)
		return *this;
	if (_n)
		delete [] _unit;
	_n = other._n;
	_unit = new ISpaceMarine*[_n];
	for (int i = 0; i < _n; i++)
		_unit[i] = other._unit[i]->clone();
	return *this;
}

int Squad::getCount() const {return _n;}

ISpaceMarine* Squad::getUnit(int ind) const 
{
	if (ind < 0 || ind >= _n)
		return NULL;
	return _unit[ind];
}

int Squad::push(ISpaceMarine* new_mem)
{
	ISpaceMarine **tmp;
	_n++;
	tmp = new ISpaceMarine*[_n];
	for (int i = 0; i < _n - 1; i++)
		tmp[i] = _unit[i];
	tmp[_n - 1] = new_mem;
	if (_n > 1)
		delete [] _unit;
	_unit = tmp;
	return _n;
}
