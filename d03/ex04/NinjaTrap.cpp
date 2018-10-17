/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:09:38 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 16:09:39 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name){
	_hit_points = 60;
	_max_hpoints = 60;
	_energy_points = 120;
	_max_energy = 120;
	_melee = 60;
	_ranged = 5;
	_armor = 0;
	std::cout << "Ninja: __\n";
}

NinjaTrap::NinjaTrap() : ClapTrap("Ninja"){
	_hit_points = 60;
	_max_hpoints = 60;
	_energy_points = 120;
	_max_energy = 120;
	_melee = 6;
	_ranged = 6;
	_armor = 0;
	std::cout << "Default Ninja: __\n";
}

NinjaTrap::~NinjaTrap(){
	std::cout << "Ninja: " << _name << " gone\n";
}

NinjaTrap::NinjaTrap(NinjaTrap const & other){
	*this = other;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & other){
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

void	NinjaTrap::rangedAttack(std::string const & target){
	std::cout << "\x1b[38;5;72mNinja" <<  _name << " attacks " <<
	 target <<  " at range, causing " << _ranged << " points of damage !\n\033[0m";
}

void	NinjaTrap::meleeAttack(std::string const & target){
	std::cout << "\x1b[38;5;72mCL4P-TP " <<  _name  << " attacks " <<
	 target <<  " at melee, causing " << _melee << " points of damage !\n\033[0m";
}

void	NinjaTrap::ninjaShoeBox(ScavTrap const & target)
{
	if (_energy_points < 25)
	{
		std::cout << "\x1b[38;5;196m" << _name << " is out of energy.\n\033[0m";
		_alive = 0;
		return ;
	}
	_energy_points -= 25;
	rangedAttack(target.get_name());
	meleeAttack(target.get_name());
	std::cout << target.get_name() << ", present for you from " << _name << "\n";
}

void	NinjaTrap::ninjaShoeBox(NinjaTrap const & target)
{
	if (_energy_points < 25)
	{
		std::cout << "\x1b[38;5;196m" << _name << " is out of energy.\n\033[0m";
		_alive = 0;
		return ;
	}
	_energy_points -= 25;
	rangedAttack(target.get_name());
	meleeAttack(target.get_name());
	std::cout << _name << " trying to hyah another ninja " << target.get_name() << "\n";
}

void	NinjaTrap::ninjaShoeBox(FragTrap const & target)
{
	if (_energy_points < 25)
	{
		std::cout << "\x1b[38;5;196m" << _name << " is out of energy.\n\033[0m";
		_alive = 0;
		return ;
	}
	_energy_points -= 25;
	rangedAttack(target.get_name());
	meleeAttack(target.get_name());
	std::cout << _name << " silently hyah Frag" << target.get_name() << "\n";
}
