/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:14:51 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:14:52 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
#define POWERFIST_HPP
#include <iostream>
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
private:

public:
	PowerFist();
	PowerFist(std::string const & name, int apcost, int damage);
	PowerFist(PowerFist const & other);
	PowerFist & operator=(PowerFist const & other);
	~PowerFist();

	void attack() const;
};


#endif

