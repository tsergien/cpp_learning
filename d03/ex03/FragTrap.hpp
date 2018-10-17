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
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	void	attack1(std::string const & target);
	void	attack2(std::string const & target);
	void	attack3(std::string const & target);
	void	attack4(std::string const & target);
	void	attack5(std::string const & target);

public:
	FragTrap(std::string name);
	FragTrap();
	~FragTrap();
	FragTrap & operator=(FragTrap const & other);
	FragTrap(FragTrap const & other);
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	vaulthunter_dot_exe(std::string const & target);
};


#endif
