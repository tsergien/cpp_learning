/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:03:12 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 12:03:14 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
#include <cstdlib>

class ScavTrap
{
	std::string _name;
	int	_hit_points;
	int	_max_hpoints;
	int	_energy_points;
	int _max_energy;
	int	_level;
	int	_melee;
	int	_ranged;
	int	_armor;
	bool	_alive;

	void	challenge1(std::string const & target);
	void	challenge2(std::string const & target);
	void	challenge3(std::string const & target);
	void	challenge4(std::string const & target);
	void	challenge5(std::string const & target);

public:
	ScavTrap(std::string name);
	ScavTrap();
	~ScavTrap();
	ScavTrap(ScavTrap const & other);
	ScavTrap & operator=(ScavTrap const & other);
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(std::string const & target);
	bool	is_alive();
	void	set_name(std::string name);

	std::string	get_name() const;
};


#endif

