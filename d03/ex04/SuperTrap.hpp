/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:14:19 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 17:14:21 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP
#include <iostream>
#include <cstdlib>

#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
	SuperTrap(std::string name);
	SuperTrap();
	~SuperTrap();
	SuperTrap & operator=(SuperTrap const & other);
	SuperTrap(SuperTrap const & other);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
};

#endif
