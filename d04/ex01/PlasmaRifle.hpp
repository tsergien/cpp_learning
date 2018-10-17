/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:14:31 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:14:32 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP
#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
private:

public:
	PlasmaRifle();
	PlasmaRifle(std::string const & name, int apcost, int damage);
	PlasmaRifle(PlasmaRifle const & other);
	PlasmaRifle & operator=(PlasmaRifle const & other);
	~PlasmaRifle();

	void attack() const;
};


#endif
