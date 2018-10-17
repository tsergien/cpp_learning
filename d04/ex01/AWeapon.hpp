/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:14:13 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:14:15 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
#define AWEAPON_HPP
#include <iostream>

class AWeapon
{
private:
	std::string _name;
	int _ap;
	int _damage;
public:
	AWeapon();
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const & other);
	AWeapon & operator=(AWeapon const & other);
	virtual ~AWeapon();

	std::string const & getName() const;
	int getDamage() const;
	int getAPCost() const;

	virtual void attack() const = 0;
};


#endif
