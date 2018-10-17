/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:14:26 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:14:27 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(): AWeapon("Plasma Rifle", 5, 21){}

PlasmaRifle::PlasmaRifle(std::string const & name, int apcost, int damage) : AWeapon(name, apcost, damage){}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & other) : AWeapon(other)
{
	*this = other;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & other){
	*((AWeapon*)this) = other;
	return *this;
}

PlasmaRifle::~PlasmaRifle(){}

void PlasmaRifle::attack() const{
	std::cout << "* piouuu piouuu piouuu *\n";
}
