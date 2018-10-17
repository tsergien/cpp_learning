/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:41:13 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 13:41:14 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <cstdlib>

class ClapTrap
{
protected:
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

public:
	ClapTrap(std::string name);
	ClapTrap();
	~ClapTrap();
	ClapTrap(ClapTrap const & other);
	ClapTrap & operator=(ClapTrap const & other);
	
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(std::string const & target);
	bool	is_alive();
	void	set_name(std::string name);

	int			get_level() const;
	int			get_energy() const;
	int			get_hp() const;
	std::string	get_name() const;
};


#endif


