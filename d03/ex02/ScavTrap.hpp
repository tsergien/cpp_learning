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
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
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
	void	challengeNewcomer(std::string const & target);
};

#endif
