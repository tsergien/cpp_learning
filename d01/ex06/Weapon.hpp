#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
	std::string	type;
public:
	Weapon(std::string type);
	std::string const & getType() const;
	void setType(std::string s);
};

#endif