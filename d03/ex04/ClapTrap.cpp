/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:41:08 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 13:41:09 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name),\
										_hit_points(100),\
										_max_hpoints(100),\
										_energy_points(50),\
										_max_energy(50),\
										 _level(1),\
										_melee(20),\
										_ranged(15),\
										_armor(3),\
										_alive(1){
	std::cout << "Clap: Let's get this party started!\n";
}

ClapTrap::ClapTrap() : _name("Trash"),\
					_hit_points(100),\
					_max_hpoints(100),\
					_energy_points(50),\
					_max_energy(50),\
					 _level(1),\
					_melee(20),\
					_ranged(15),\
					_armor(3),\
					_alive(1){
	std::cout << "Default Clap: Let's get this party started!\n";
}

ClapTrap::~ClapTrap(){
	std::cout << "Clap: " << _name << " gone to heaven\n";
}

ClapTrap::ClapTrap(ClapTrap const & other){
	*this = other;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & other){
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

void	ClapTrap::takeDamage(unsigned int amount){
	amount = (int)(amount - _armor) < 0 ? 1 : (amount - _armor);
	_hit_points -= amount;
	if (_hit_points < 0)
		_hit_points = 0;
	std::cout  << _name << " take damege " <<
	 "causing " << amount << " points of damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount){
	_hit_points += amount;
	_energy_points += 25;
	if (_hit_points > _max_hpoints)
		_hit_points = _max_hpoints;
	if (_energy_points > _max_energy)
		_energy_points = _max_energy;
	std::cout << _name << " being repaired with "
	<< amount << " points!";
	std::cout << "\x1b[38;5;156m I found health!\033[0m\n";
}


std::string	ClapTrap::get_name() const{return _name;}

bool	ClapTrap::is_alive(){return _alive;}

int		ClapTrap::get_level() const{return _level;}

void		ClapTrap::set_name(std::string name){_name = name;}

int			ClapTrap::get_energy() const{return _energy_points;}

int			ClapTrap::get_hp() const{return _hit_points;}