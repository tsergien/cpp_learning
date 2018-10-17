/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:10:52 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 09:10:53 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>
#include <cstdlib>

class FragTrap
{
	std::string _name;
	int	_hit_points;
	int	_max_hpoints;
	int	_energy_points;
	int	_max_energy;
	int	_level;
	int	_melee;
	int	_ranged;
	int	_armor;
	bool	_alive;
	void	attack1(std::string const & target);
	void	attack2(std::string const & target);
	void	attack3(std::string const & target);
	void	attack4(std::string const & target);
	void	attack5(std::string const & target);

public:
	FragTrap(std::string name);
	FragTrap();
	~FragTrap();
	FragTrap(FragTrap const & other);
	FragTrap & operator=(FragTrap const & other);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);
	std::string	get_name() const;
	int		get_level() const;
	void	set_name(std::string name);
	bool	is_alive();
};


#endif
