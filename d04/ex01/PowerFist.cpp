/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:14:44 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:14:46 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(): AWeapon("Power Fist", 8, 50){}

PowerFist::PowerFist(std::string const & name, int apcost, int damage) : AWeapon(name, apcost, damage){}

PowerFist::PowerFist(PowerFist const & other) : AWeapon(other)
{
	*this = other;
}

PowerFist & PowerFist::operator=(PowerFist const & other){
	*((AWeapon*)this) = other;
	return *this;
}

PowerFist::~PowerFist(){}

void PowerFist::attack() const{
	std::cout << "* pschhh... SBAM! *\n";
}
