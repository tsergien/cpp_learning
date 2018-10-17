#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	std::string	_name;
	Weapon&		_weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	void attack() const;
};

#endif
