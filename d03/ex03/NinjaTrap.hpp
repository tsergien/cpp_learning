/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:09:44 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 16:09:45 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP
#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(std::string name);
	NinjaTrap();
	~NinjaTrap();
	NinjaTrap & operator=(NinjaTrap const & other);
	NinjaTrap(NinjaTrap const & other);
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	ninjaShoeBox(NinjaTrap const & target);
	void	ninjaShoeBox(FragTrap const & target);
	void	ninjaShoeBox(ScavTrap const & target);
};


#endif

