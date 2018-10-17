/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:14:08 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:14:09 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::~AWeapon(){}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name),\
																	_ap(apcost),\
																	_damage(damage)
{}

AWeapon::AWeapon(AWeapon const & other){
	*this = other;
}

AWeapon & AWeapon::operator=(AWeapon const & other)
{
	_name = other.getName();
	_ap = other.getAPCost();
	_damage = other.getDamage();
	return *this;
}

int AWeapon::getAPCost() const{return _ap;}
int AWeapon::getDamage() const{return _damage;}
std::string const & AWeapon::getName() const{return _name;}
