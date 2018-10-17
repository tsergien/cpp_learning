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

FragTrap::FragTrap(std::string name) : _name(name), _hit_points(100), _max_hpoints(100), _energy_points(100),\
									_max_energy(100),_level(1), _melee(30), _ranged(20), _armor(5), _alive(1){
	std::cout << "Default Frag:.-- start bootup sequence.\n";
}

FragTrap::FragTrap() : _name("TRSH-TP"), _hit_points(100), _max_hpoints(100), _energy_points(100),\
									_max_energy(100), _level(1), _melee(30), _ranged(20), _armor(5), _alive(1){
	std::cout << "Frag:.-- start bootup sequence.\n";
}

FragTrap::~FragTrap(){std::cout << _name << " is dead.\n";}

FragTrap::FragTrap(FragTrap const & other){
	*this = other;
}

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
	std::cout << "FR4G-TP " << _name << " attacks " <<
	 target <<  " at range, causing " << _ranged << " points of damage !\n";
}

void	FragTrap::meleeAttack(std::string const & target){
	std::cout << "FR4G-TP " << _name << " attacks " <<
	 target <<  " at melee, causing " << _melee << " points of damage !\n";
}

void	FragTrap::takeDamage(unsigned int amount){
	amount = (int)(amount - _armor) < 0 ? 1 : (amount - _armor);
	_hit_points -= amount;
	if (_hit_points < 0)
		_hit_points = 0;
	std::cout << "FR4G-TP " << _name << " take damege " <<
	 "causing " << amount << " points of damage !\n";
}

void	FragTrap::beRepaired(unsigned int amount){
	_hit_points += amount;
	_energy_points += 25;
	if (_hit_points > _max_hpoints)
	{
		_level += 1;
		_hit_points = _max_hpoints;
	}
	if (_energy_points > _max_energy)
		_energy_points = _max_energy;
	std::cout << "\x1b[38;5;156mFR4G-TP " << _name << " being repaired with "
	<< amount << " points! ";
	std::cout << "Sweet life juice!\033[0m\n";
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

std::string	FragTrap::get_name() const{return _name;}

int		FragTrap::get_level() const{return _level;}

bool	FragTrap::is_alive(){return _alive;}

void	FragTrap::set_name(std::string name){_name = name;}
