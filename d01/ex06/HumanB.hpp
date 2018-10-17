#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	std::string	_name;
	Weapon* 	_weapon;
public:
	~HumanB();
	HumanB(std::string name);
	void attack() const;
	void setWeapon(Weapon &weapon);
};

#endif