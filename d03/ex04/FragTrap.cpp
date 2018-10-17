/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:10:47 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 09:10:48 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_energy_points = 100;
	_max_energy = 100;
	_armor = 5;
	_melee = 30;
	_ranged = 20;
	std::cout << "Default Frag:.-- start bootup sequence.\n";
}

FragTrap::FragTrap() : ClapTrap("TRSH-TP")
{
	_energy_points = 100;
	_max_energy = 100;
	_armor = 5;
	_melee = 30;
	_ranged = 20;
	std::cout << "Frag:.-- start bootup sequence.\n";
}

FragTrap::~FragTrap(){std::cout << "Frag: " << _name << " is dead.\n";}

FragTrap::FragTrap(FragTrap const & other){*this = other;}

FragTrap & FragTrap::operator=(FragTrap const & other){
	_name = other._name;
	_hit_points = other._hit_points;
	_max_hpoints = other._max_hpoints;
	_energy_points = other._energy_points;
	_max_energy = other._max_energy;
	_level = other._level;
	_melee = other._melee;
	_ranged = other._ranged;
	_armor = other._armor;
	_alive = other._alive;
	return *this;
}

void	FragTrap::rangedAttack(std::string const & target){
	std::cout << "\x1b[38;5;27mFrag " <<  _name << " attacks " <<
	 target <<  " at range, causing " << _ranged << " points of damage !\n\033[0m";
}

void	FragTrap::meleeAttack(std::string const & target){
	std::cout << "\x1b[38;5;27mFrag " <<  _name  << " attacks " <<
	 target <<  " at melee, causing " << _melee << " points of damage !\n\033[0m";
}

void	FragTrap::attack1(std::string const & target){
	meleeAttack(target);
	std::cout << "\x1b[38;5;104mFreeze! I don't know why I said that.\n\n\033[0m";
}
void	FragTrap::attack2(std::string const & target){
	meleeAttack(target);
	std::cout << "\x1b[38;5;104mLook out, a Badass!\n\n\033[0m";
}
void	FragTrap::attack3(std::string const & target){
	rangedAttack(target);
	std::cout << "\x1b[38;5;104mDon't tell me that wasn't awesome!\n\n\033[0m";
}
void	FragTrap::attack4(std::string const & target){
	rangedAttack(target);
	std::cout << "\x1b[38;5;104mI am a tornado of death and bullets!\n\n\033[0m";
}
void	FragTrap::attack5(std::string const & target){
	rangedAttack(target);
	std::cout << "\x1b[38;5;104mEat bomb, baddie!\n\n\033[0m";
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (_energy_points < 25)
	{
		std::cout << "\x1b[38;5;196m" << _name << " is out of energy.\n\033[0m";
		_alive = 0;
		return ;
	}
	_energy_points -= 25;
	void (FragTrap::*attacks[5]) (std::string const & target);
	attacks[0] = &FragTrap::attack1;
	attacks[1] = &FragTrap::attack2;
	attacks[2] = &FragTrap::attack3;
	attacks[3] = &FragTrap::attack4;
	attacks[4] = &FragTrap::attack5;
	int r = rand() % 5;
	for (int i = 0 ; i < 5; i++)
		if (i == r)
			(this->*attacks[i])(target);
}
