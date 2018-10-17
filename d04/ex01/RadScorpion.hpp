/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:16:01 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:16:02 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP
#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy
{
private:

public:
	RadScorpion();
	RadScorpion(int hp, std::string const & type);
	RadScorpion(RadScorpion const & other);
	RadScorpion const & operator=(RadScorpion const & other);
	~RadScorpion();

	virtual void takeDamage(int);
};

#endif

