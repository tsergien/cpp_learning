/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:16:10 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:16:11 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name(""), _ap(40), weapon(NULL){}

Character::Character(std::string const & name) : _name (name), _ap(40), weapon(NULL){}

Character::Character(Character const & other){
	*this = other;
}

Character const & Character::operator=(Character const & other){
	_ap = other.getAP();
	_name = other.getName();
	if (armed())
		delete weapon;
	equip(other.weapon);
	return *this;
}

Character::~Character(){
	if (armed())
		delete weapon;
}

void Character::recoverAP(){
	_ap += 10;
	if (_ap > 40)
		_ap = 40;
}
void Character::equip(AWeapon* w){
	weapon = w;
}
void Character::attack(Enemy* e){
	if (weapon == NULL || e == NULL)
		return ;
	int ap = weapon->getAPCost();
	int damage = weapon->getDamage();
	if (_ap - ap > 0)
	{
		_ap -= ap;
		std::cout << _name << " attacks " << e->getType() << " with a " << (getWeapon())->getName() << "\n";
		getWeapon()->attack();
		e->takeDamage(damage);
		if (e->getHP() <= 0)
			delete e;
	}
}

std::string const & Character::getName() const{return _name;}
AWeapon const * Character::getWeapon() const{return weapon;}
int Character::getAP() const{return _ap;}
bool Character::armed() const{return (weapon == NULL ? 0 : 1);}

std::ostream & operator<<(std::ostream & os, Character const & rhs){
	os << rhs.getName() << " has " << rhs.getAP() << " AP and ";
	if (rhs.armed())
		os << "wields a " << rhs.getWeapon()->getName() << "\n";
	else
		os << "is unarmed\n";
	return os;
}
