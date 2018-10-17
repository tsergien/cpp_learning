/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:15:44 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:15:45 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTAMNT_HPP
#define SUPERMUTAMNT_HPP
#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy
{
private:

public:
	SuperMutant();
	SuperMutant(int hp, std::string const & type);
	SuperMutant(SuperMutant const & other);
	SuperMutant const & operator=(SuperMutant const & other);
	~SuperMutant();

	virtual void takeDamage(int);
};

#endif

