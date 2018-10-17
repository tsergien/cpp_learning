/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:14:14 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 17:14:15 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) :  ClapTrap(name), NinjaTrap("Super"), FragTrap("Super"){
	_hit_points = FragTrap::_hit_points;
	_max_hpoints = FragTrap::_max_hpoints;
	_energy_points = NinjaTrap::_energy_points;
	_max_energy = NinjaTrap::_max_energy;
	_melee = NinjaTrap::_melee;
	_ranged = FragTrap::_ranged;
	_armor = FragTrap::_armor;
	std::cout << "Super: __ " << this->_name << "\n";
}

SuperTrap::SuperTrap() : ClapTrap("Super"), NinjaTrap("Super"), FragTrap("Super"){
	_hit_points = FragTrap::_hit_points;
	_max_hpoints = FragTrap::_max_hpoints;
	_energy_points = NinjaTrap::_energy_points;
	_max_energy = NinjaTrap::_max_energy;
	_melee = NinjaTrap::_melee;
	_ranged = FragTrap::_ranged;
	_armor = FragTrap::_armor;
	std::cout << "Default Super: __ " << this->_name << "\n";
}

SuperTrap::~SuperTrap(){
	std::cout << "Super: " << this->_name << " gone\n";
}

SuperTrap::SuperTrap(SuperTrap const & other){
	*this = other;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & other){
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

void	SuperTrap::rangedAttack(std::string const & target){
	FragTrap::meleeAttack(target);
}

void	SuperTrap::meleeAttack(std::string const & target){
	NinjaTrap::meleeAttack(target);
}
