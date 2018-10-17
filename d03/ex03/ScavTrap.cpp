/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:03:06 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 12:03:08 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "Scav: -- start bootup sequence.\n";
}

ScavTrap::ScavTrap() : ClapTrap("TRSH-TP"){
	std::cout << "Default Scav: -- start bootup sequence.\n";
}

ScavTrap::~ScavTrap(){
	std::cout << "Scav: " << _name << " is dead\n";
}

ScavTrap::ScavTrap(ScavTrap const & other){
	*this = other;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other){
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

void	ScavTrap::rangedAttack(std::string const & target){
	std::cout << "\x1b[38;5;72mCL4P-TP " <<  _name << " attacks " <<
	 target <<  " at range, causing " << _ranged << " points of damage !\n\033[0m";
}

void	ScavTrap::meleeAttack(std::string const & target){
	std::cout << "\x1b[38;5;72mCL4P-TP " <<  _name  << " attacks " <<
	 target <<  " at melee, causing " << _melee << " points of damage !\n\033[0m";
}

void	ScavTrap::challenge1(std::string const & target){
	meleeAttack(target);
	std::cout << "\x1b[38;5;104m Super cilling combo attack\n\n\033[0m";
}
void	ScavTrap::challenge2(std::string const & target){
	rangedAttack(target);
	std::cout << "\x1b[38;5;104m Step right up, to the Bulletnator 9000! \n\n\033[0m";
}
void	ScavTrap::challenge3(std::string const & target){
	meleeAttack(target);
	std::cout << "\x1b[38;5;104m Stop me before I kill again, except don't!\n\n\033[0m";
}
void	ScavTrap::challenge4(std::string const & target){
	rangedAttack(target);
	std::cout << "\x1b[38;5;104m Is it dead? Can, can I open my eyes now?\n\n\033[0m";
}
void	ScavTrap::challenge5(std::string const & target){
	std::cout << "\x1b[38;5;104m Bad guy " << target << " go ka-boom!\n\n\033[0m";
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	if (_energy_points < 25)
	{
		std::cout << "\x1b[38;5;196m" << _name << " is out of energy.\n\033[0m";
		_alive = 0;
		return ;
	}
	_energy_points -= 25;
	void (ScavTrap::*challenges[5]) (std::string const & target);
	challenges[0] = &ScavTrap::challenge1;
	challenges[1] = &ScavTrap::challenge2;
	challenges[2] = &ScavTrap::challenge3;
	challenges[3] = &ScavTrap::challenge4;
	challenges[4] = &ScavTrap::challenge5;
	int r = rand() % 5;
	for (int i = 0 ; i < 5; i++)
		if (i == r)
			(this->*challenges[i])(target);
}
